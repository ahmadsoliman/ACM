package jgam.util;

/**
 * An array of bits.
 *
 * It has fixed size.
 * Each bit can be set or cleared.
 *
 * The array can be exported as a byte-array.
 * In order to do so, the order of bits must be set.
 *
 * Mode MSB_FIRST exports the first bit in the highest (0x80) bit of the first
 * byte
 * Mode LSB_FIRST exports the first bit in the lowest (0x01) bit of the first
 * byte.
 *
 * Ideas:
 * Exporting to integer/long/int array ...
 *
 * @author Mattias Ulbrich
 */
public class BitArray {

    public static final int MSB_FIRST = 0;
    public static final int LSB_FIRST = 1;

    private boolean bits[];

    public BitArray(int size) {
        bits = new boolean[size];
    }

    public void setBit(int index, boolean value) {
        bits[index] = value;
    }

    public void setBit(int index, int value) {
        setBit(index, value != 0);
    }

    public void setBit(int index) {
        setBit(index, true);
    }

    public void clearBit(int index) {
        setBit(index, false);
    }

    public byte[] toByteArray(int mode) {
        byte[] ret = new byte[(bits.length+7)/8];

        for (int i = 0; i < bits.length; i++) {
            if(bits[i] == true){
                int bytePos = i / 8;
                int bitPos = i % 8;
                if (mode == MSB_FIRST) {
                    bitPos = 7 - bitPos;
                }
                ret[bytePos] |= (1<<bitPos);
            }
        }
        return ret;
    }

    public byte[] toByteArray() {
        return toByteArray(MSB_FIRST);
    }
}
