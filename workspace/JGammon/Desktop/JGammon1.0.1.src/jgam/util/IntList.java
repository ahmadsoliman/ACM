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

/**
 * A List-Type for the basic type integer.
 *
 * @author Mattias Ulbrich
 */
public class IntList {

    // the stored data
    private int array[];
    // the size of this list
    private int size;

    /**
     * create a new IntList and initially provide space for a given number
     * of int-Values.
     *
     * If this number is reached new space is allocated automatically.
     * @param initsize the number of int-Values to initially provide space for.
     */
    public IntList(int initsize) {
        size = 0;
        array = new int[initsize];
    }

    /**
     * create a new IntList with an inital space of 10.
     */
    public IntList() {
        this(10);
    }

    /**
     * create a new IntList from an int-array. This array is cloned and the
     * clone used as underlying data.
     * @param a an int-array which must not be null
     */
    public IntList(int[] a) {
        array = (int[])a.clone();
        size = array.length;
    }

    /**
     * create a new IntList from a part of an array of int.
     * @param a array to take from
     * @param start index to start at
     * @param length number of int-values to copy.
     */
    public IntList(int[] a, int start, int length) {
        array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = a[start+i];
        }
        size = length;
    }

    /**
     * add an int-value to the end of the list.
     * @param value int value to add
     */
    public void add(int value) {
        if (size == array.length) {
            int[] old = array;
            array = new int[old.length + 10];
            System.arraycopy(old, 0, array, 0, old.length);
        }
        array[size++] = value;
    }

    /**
     * remove the intvalue at a given index
     * @param pos index to be removed.
     * @throws IndexOutOfBoundsException
     */
    public void removeIndex(int pos) {
        if (pos >= size) {
            throw new IndexOutOfBoundsException("remove: " + pos);
        }
        for (int i = pos; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    /**
     * remove a value from this IntList. Remove it at most once.
     * @param val int-value to be removed
     * @return true iff the value has been found and removed
     */
    public boolean remove(int val) {
        for (int i = 0; i < size; i++) {
            if (array[i] == val) {
                removeIndex(i);
                return true;
            }
        }
        return false;
    }

    /**
     * get the value at a certain index.
     * @param index index to get the value of
     * @return int-value at this index
     * @throws IndexOutOfBoundsException
     */
    public int at(int index) {
        return array[index];
    }

    /**
     *
     * @return the number of int-values in this IntList
     */
    public int length() {
        return size;
    }

    /**
     * @return an array-representation of this IntList.
     */
    public int[] toArray() {
        int[] ret = new int[size];
        System.arraycopy(array, 0, ret, 0, size);
        return ret;
    }

    /**
     * is this IntList empty?
     * @return true iff length() == 0
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * remove the maximum from the IntList. remove it only once.
     */
    public void removeMax() {
        int max = Integer.MIN_VALUE;
        int maxpos = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] > max) {
                max = array[i];
                maxpos = i;
            }
        }
        removeIndex(maxpos);
    }

    /**
     * is a certain int-value present in the IntList
     * @param value value to searched
     * @return true iff value is in this IntList.
     */
    public boolean contains(int value) {
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                return true;
            }
        }
        return false;
    }

    /**
     * the maximum in this list.
     * @return int that is ">=" to all elements in the list
     */
    public int max() {
        int m = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            if (array[i] > m) {
                m = array[i];
            }
        }
        return m;
    }

    /**
     * the minimum in this list.
     * @return int that is "<=" to all elements in the list
     */
    public int min() {
        int m = Integer.MAX_VALUE;
        for (int i = 0; i < size; i++) {
            if (array[i] < m) {
                m = array[i];
            }
        }
        return m;
    }

    /**
     * clone this list. The underlying array is deepcopied.
     * @return Object
     */
    public Object clone() {
        return new IntList(array, 0, size);
    }

    /**
     * get an IntList that contains every number contained in this but is minimal
     *
     * @return IntList the unique Sub-IntList
     */
    public IntList distinctValues() {
        IntList ret = new IntList();
        for (int i = 0; i < size; i++) {
            if(!ret.contains(array[i]))
                ret.add(array[i]);
        }
        return ret;
    }

}
