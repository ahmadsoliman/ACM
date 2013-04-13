/*
 JGammon: A Backgammon client with nice graphics written in Java
 Copyright (C) 2005 Mattias Ulbrich

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
package jgam;

import java.io.*;
import java.net.*;
import java.util.*;

import jgam.util.AsynchronousWaitingWindow;
import jgam.util.*;

/**
 * Use this class to handle connections between jgam-programs.
 *
 * The reader is constantly read (in run())
 * If a message (a line ending with \n) is read
 * all ConnectionListeners are informed
 * if the reader cant read any more (socket error) also
 *
 * One listener is used to feed a pipedReader that only has got the
 * lines that are relevant for the game.
 *
 * @author Mattias Ulbrich
 */
public class GameConnection extends Thread {

    private Socket socket;
    private BufferedReader reader;
    private Writer writer;
    private PipedWriter gameProducerWriter;
    private BufferedReader gameReader;

    private List connectionListeners = new ArrayList();

    private ResourceBundle msg = ResourceBundle.getBundle("jgam.msg.JGam");

    /**
     * create a new connection by connecting to a server
     * @param servername server
     * @param portno Port number
     */
    public GameConnection(String servername, int portno) throws
            UnknownHostException, IOException, ProtocolException {
        super("GameConnection-Producer");

        socket = new Socket(servername, portno);
        init();

    }


    /**
     * create a server waiting for connection
     *
     * @param portno int
     */
    public GameConnection(int portno) throws Exception {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(portno);
            serverSocket.setSoTimeout(3000);

            final AsynchronousWaitingWindow window = new
                    AsynchronousWaitingWindow(
                            JGammon.jgammon().getFrame(),
                            msg.getString("openingServer"),
                            msg.getString("serverListening"),
                            msg.getString("abort"));

            final ServerSocket locServerSocket = serverSocket;
            // the following is active waiting and may not happen
            // in the awt event-queue -> start thread!
            new Thread(new Runnable() {
                public void run() {
                    while (socket == null && !window.buttonPressed()) {
                        try {
                            socket = locServerSocket.accept();
                        } catch (SocketTimeoutException ex) {
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                    }
                    window.setVisible(false);
                }
            }).start();

            window.setVisible(true);

            if (socket == null) {
                throw new Exception(
                        "Server interrupted or no connection setup possible");
            }

            serverSocket.close();
            init();
        } catch (Exception ex) {
            if (serverSocket != null) {
                serverSocket.close();
            }
            close();
            throw ex;
        }
    }

    private void init() throws IOException, ProtocolException {

        gameProducerWriter = new PipedWriter();
        gameReader = new BufferedReader(new PipedReader(gameProducerWriter));

        reader = new BufferedReader(new InputStreamReader(socket.
                getInputStream(),
                "UTF-8"));
        writer = new OutputStreamWriter(socket.getOutputStream(), "UTF-8");

        // protocolling
        if (Boolean.getBoolean("jgam.debug")) {
            writer = new ProtocollingWriter(writer);
            reader = new BufferedReader(new ProtocollingReader(reader), 1); // no buffering!
        }

        writer.write("SERVUS JGAM - This is JGammon Version " +
                     JGammon.getExtVersion() +
                     "\n");
        writer.flush();
        String version = reader.readLine();
        if (!version.startsWith("SERVUS JGAM")) {
            close();
            throw new ProtocolException(
                    "This seems not to be a JGAM-partner");
        }
        System.out.println("Opponent's version: " + version);

        // add game reader producer listener
        addConnectionListener(new GameReaderConnectionListener());

        // start producing thread
        this.start();
    }

    BufferedReader getGameReader() {
        return gameReader;
    }

    Writer getWriter() {
        return writer;
    }

    public void addConnectionListener(ConnectionListener cl) {
        assert cl != null:"ConnectionListerners must not be null";
        synchronized (connectionListeners) {
            connectionListeners.add(cl);
        }
    }

    public void removeConnectionListener(ConnectionListener cl) {
        synchronized (connectionListeners) {
            connectionListeners.remove(cl);
        }
    }


    public void close() {
        if (socket != null) {
            try {
                socket.close();
            } catch (IOException ex) {}
        }
    }

    synchronized public void run() {
        while (true) {
            //
            // read line
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException ex) {}

            if (line == null) {
                break;
            }

            //
            // inform listeners
            ConnectionMessage cm = new ConnectionMessage(line);
            synchronized (connectionListeners) {
                for (Iterator iter = connectionListeners.iterator();
                                     iter.hasNext(); ) {
                    ConnectionListener cl = (ConnectionListener) iter.next();
                    try {
                        cl.handleConnectionMessage(cm);
                    } catch (Exception ex) {
                        System.err.println(
                                "handleConnectionMessage caused an exception:");
                        ex.printStackTrace();
                    }
                }
            }
        }

        //
        // inform on closed too
        ConnectionMessage cm = new ConnectionMessage(ConnectionMessage.CLOSED);
        synchronized (connectionListeners) {
            for (Iterator iter = connectionListeners.iterator();
                                 iter.hasNext(); ) {
                ConnectionListener cl = (ConnectionListener) iter.next();
                try {
                    cl.handleConnectionMessage(cm);
                } catch (Exception exx) {
                    System.err.println(
                            "handleConnectionMessage caused an exception:");
                    exx.printStackTrace();
                }
            }
        }
    }


    public int[] rollDice(int count) throws ProtocolException,
            IOException {
        SecureRoll secureDice = new SecureRoll();
        if (Boolean.getBoolean("jgam.unsecuredice")) {
            secureDice.negotiateUnsecure(getGameReader(), getWriter());
        } else {
            secureDice.negotiate(getGameReader(), getWriter());
        }

        return secureDice.getDice(count);
    }


    /**
     * Use this class to feed the gameReader.
     */
    private class GameReaderConnectionListener implements ConnectionListener {
        public void handleConnectionMessage(ConnectionMessage cm) {
            if (cm.getType() == cm.MESSAGE && !cm.getMessage().startsWith(">")) {
                try {
                    gameProducerWriter.write(cm.getMessage() + "\n");
                } catch (IOException ex) {
                    // try a second time after waiting a bit
                    try {
                        Thread.sleep(400);
                        gameProducerWriter.write(cm.getMessage() + "\n");
                    } catch(Exception ex1) {
                        throw new RuntimeException(ex);
                    }
                }
            }
        }
    }


    public boolean receiveColorIsWhite() throws ProtocolException, IOException {

        String line = getGameReader().readLine();
        if (!line.startsWith("YOUPLAY ")) {
            throw new ProtocolException("YOUPLAY expected; got:" + line);
        }

        return line.equals("YOUPLAY WHITE");
    }

    public void sendColor(boolean isWhite) throws IOException {
        getWriter().write("YOUPLAY " + (isWhite ? "WHITE" : "BLUE") + "\n");
        getWriter().flush();
    }

}
