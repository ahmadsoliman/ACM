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

import java.io.BufferedReader;
import java.io.Writer;
import java.util.Random;

import com.Ostermiller.util.Base64;
import java.io.IOException;
import java.security.*;

/**
 *
 * Protocol for secure dice!
 *
 * Bargain the value for the dice so that none of the players can cheat.
 *
 * SHA is a message digest-algorithm.
 *
 * R is a randomly generated 64-bit value with
 *       the first byte < 36
 * SHA_R = SHA("SECROLL R")
 *
 * R for player1, Q for player2
 *
 * Each player performs the following symmetrically:
 *
 *  1. send    SECROLL_VEILED SHA_R
 *  2. receive SECROLL_VEILED SHA_Q
 *  3. send    SECROLL R
 *  4. receive SECROLL Q
 *  5. validate SHA_Q = SHA("SECROLL Q")
 *  2. The final dice are obtained by adding the first byte of R and Q
 *     modulo 36
 *
 * This first byte ought to be 0 <= x < 36.
 *
 * dice1 = X % 6
 * dice2 = X / 6
 *
 * For legacy reasons there is also an unsecure communication implemented.
 *
 * @author Mattias Ulbrich
 */
public class SecureRoll {

    private final static int PAD_LENGTH = 8;

    Random random;

    int dice[] = null;

    public SecureRoll() {
        random = new Random();
    }


    public void negotiate(BufferedReader r, Writer w) throws IOException,
            ProtocolException {

        byte[] myPad = new byte[PAD_LENGTH];
        random.nextBytes(myPad);
        myPad[0] = (byte) random.nextInt(36);

        MessageDigest md;
        try {
            md = MessageDigest.getInstance("SHA");
        } catch (NoSuchAlgorithmException ex) {
            throw new ProtocolException(ex);
        }

        // STEP 1
        //
        md.digest("SECURE DICE".getBytes());
        byte[] myDigest = md.digest(myPad);
        String stringMyDigest = Base64.encodeToString(myDigest, false);

        String message = "SECDICE_VEILED " + stringMyDigest;

        w.write(message + "\n");
        w.flush();

        // STEP 2
        //
        String line = r.readLine();
        if (!line.startsWith("SECDICE_VEILED ")) {
            throw new ProtocolException("SECDICE_VEILED expected, got: " + line);
        }
        byte[] hisDigest = Base64.decodeToBytes(line.substring(15));

        // STEP 3
        //
        message = "SECDICE " + Base64.encodeToString(myPad, false);
        w.write(message + "\n");
        w.flush();

        // STEP 4
        //
        line = r.readLine();
        if (!line.startsWith("SECDICE ")) {
            throw new ProtocolException("SECDICE expected, got: " + line);
        }
        byte[] hisPad = Base64.decodeToBytes(line.substring(8));

        // Check that digest is ok!
        md.reset();
        md.digest("SECURE DICE".getBytes());
        if (!MessageDigest.isEqual(hisDigest, md.digest(hisPad))) {
            throw new ProtocolException(
                    "The fingerprint and the pad do not match!");
        }

        // calc the value!
        int D = (hisPad[0] + myPad[0]) % 36;

        dice = new int[2];
        dice[0] = (D / 6)+1;
        dice[1] = (D % 6)+1;
    }

    public void negotiateUnsecure(BufferedReader r, Writer w) throws IOException,
            ProtocolException {

        int rand = random.nextInt(36);

        // send mine
        //
        w.write("DICE "+rand+"\n");
        w.flush();

        // receive other
        //
        String line = r.readLine();
        if (!line.startsWith("DICE ")) {
            throw new ProtocolException("DICE expected, got: " + line);
        }

        int hisRand;
        hisRand = Integer.parseInt(line.substring(5));

        // calc the value!
        int D = (rand + hisRand) % 36;

        dice = new int[2];
        dice[0] = (D / 6)+1;
        dice[1] = (D % 6)+1;

    }


    public int getOneDice() {
        return dice[0];
    }

    public int[] getDice() {
        return dice;
    }

    public int[] getDice(int count) {
        if (count == 1) {
            return new int[] {dice[0]};
        } else if (count == 2) {
            return dice;
        } else {
            throw new IndexOutOfBoundsException("dice must be 1 or 2");
        }
    }
}

