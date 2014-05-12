package tables;

import java.util.ArrayList;
import java.util.Arrays;

import tablesExceptions.IndexOutOfTableBoundsException;
import tablesExceptions.NonPositiveHeightException;
import tablesExceptions.OutOfTableException;

/**
 * SingleColumnTableRareResizes creates a table with a single column and rows of
 * different heights. Operations implemented are, updating a row height and
 * querying the index of a cell at a certain height.
 * 
 * This implementation assumes that resize() method is rarely called in
 * correspondence to findCell(), a static moderate sized table in a web page
 * with a huge number of mouse clicks checks would need to use this.
 * 
 * This class assumes that the total height of the table in pixels is not huge
 * (ie. not larger than 10^7 pixels), it uses O(m) memory, where m is the total
 * number of pixels.
 * 
 * findCell() runs in O(1), while resize() runs in O(h*m), where h is the
 * absolute difference between the old and new height of the cell and m is the
 * total number of pixels.
 * 
 * Zero and negative row heights are not allowed and throw exceptions.
 * 
 */
public class SingleColumnTableRareResizes {

	/*
	 * The current table total height.
	 */
	private int tableHeight;
	/*
	 * The current heights of each row in the table.
	 */
	private int rowHeights[];
	/*
	 * A dynamic array which stores the index of the row at each pixel along the
	 * total height of the table.
	 */
	private ArrayList<Integer> rowAtHeight;

	/**
	 * Class constructor specifying the array of heights of each row.
	 * 
	 * @throws NonPositiveHeightException
	 *             if a non positive height occurred
	 */
	public SingleColumnTableRareResizes(int[] heights)
			throws NonPositiveHeightException {

		rowHeights = heights;

		tableHeight = 0;
		for (int i = 0; i < heights.length; i++) {

			if (heights[i] < 1) {
				throw new NonPositiveHeightException(heights[i]);
			}

			tableHeight += heights[i];
		}

		rowAtHeight = new ArrayList<Integer>(tableHeight);

		rowAtHeight.add(0);
		for (int i = 0; i < heights.length; i++) {
			for (int j = 1; j <= heights[i]; j++) {
				rowAtHeight.add(i);
			}
		}
	}

	/**
	 * Class constructor specifying a number of rows with equal heights.
	 * 
	 * @throws NonPositiveHeightException
	 *             if a non positive height was supplied
	 */
	public SingleColumnTableRareResizes(int height, int numRows)
			throws NonPositiveHeightException {
		
		this(createArray(height, numRows));
	}

	/**
	 * Resizes a single row at index, with the new value height.
	 * 
	 * @param index
	 *            the index of the row to be changed
	 * @param height
	 *            the new height of the row
	 * @throws IndexOutOfTableBoundsException
	 *             if the index is out of bounds
	 * @throws NonPositiveHeightException
	 *             if a non positive height was supplied
	 */
	public void resize(int index, int height)
			throws IndexOutOfTableBoundsException, NonPositiveHeightException {

		if (index < 0 || index >= rowHeights.length) {
			throw new IndexOutOfTableBoundsException(index);
		}

		if (height < 1) {
			throw new NonPositiveHeightException(height);
		}

		/*
		 * The height at which cell at index starts, starts at 1 to skip pixel
		 * 0 which belongs by convention to cell 0.
		 */
		int heightIndex = 1;
		for (int i = 0; i < index; i++) {
			heightIndex += rowHeights[i];
		}
		
		// the difference between new and old heights of the row  
		int diff = height - rowHeights[index];
		
		// increases or decreases total table height
		tableHeight += diff;
		
		// update row height
		rowHeights[index] = height;
		
		// if new is shorter than old height then remove diff pixels from row
		while (diff < 0) {
			rowAtHeight.remove(heightIndex);
			diff++;
		}
		
		// if new is longer than old height then add diff pixels to row
		while (diff > 0) {
			rowAtHeight.add(heightIndex, index);
			diff--;
		}
	}

	/**
	 * Returns the index of the cell at which the point being queried is
	 * incident. If a tie occurs the index of the upper cell will be returned.
	 * 
	 * @param point
	 *            the height from the top that needs to be queried
	 * @return the index of the cell at the specified point
	 * @throws OutOfTableException
	 *             if the point is out of the table bounds
	 */
	public int findCell(int point) throws OutOfTableException {

		if (point < 0 || point >= rowAtHeight.size()) {
			throw new OutOfTableException(point);
		}

		return rowAtHeight.get(point);
	}

	/**
	 * Returns the current total height of the Single Column Table.
	 * 
	 * @return table height
	 */
	public int getTableHeight() {
		
		return tableHeight;
	}

	/**
	 * Returns an integer array with the heights of the rows.
	 * 
	 * @return rows heights
	 */
	public int[] getHeights() {
		
		return rowHeights;
	}

	public String toString() {
		
		return Arrays.toString(rowHeights);
	}

	/*
	 * A helper method that returns a new integer array filled with numRows rows
	 * with specified height.
	 */
	private static int[] createArray(int height, int numRows) {
		
		int heights[] = new int[numRows];
		Arrays.fill(heights, height);
		return heights;
	}
}
