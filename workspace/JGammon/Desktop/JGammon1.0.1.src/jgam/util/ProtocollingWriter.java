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
package jgam.util;

import java.io.FilterWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * protocol each outgoing line to System.err (ending with '\n')
 *
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class ProtocollingWriter extends Writer {
    public ProtocollingWriter(Writer out) {
        this.out = out;
    }

    private Writer out;
    private StringBuffer buf = new StringBuffer();

    public void write(char cbuf[], int off, int len) throws IOException {
        out.write(cbuf, off, len);

        for(int i = 0; i < len; i++) {
            char c = cbuf[off + i];
            if (c == '\n') {
                System.err.println("MSG out:    >> " + buf.toString());
                buf = new StringBuffer();
            } else {
                buf.append((char) c);
            }
        }
    }

    public void flush() throws IOException {
        out.flush();
    }

    public void close() throws IOException {
        out.close();
    }
}
