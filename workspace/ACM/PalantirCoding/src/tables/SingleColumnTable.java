package tables;

import java.util.Arrays;

import tablesExceptions.IndexOutOfTableBoundsException;
import tablesExceptions.NonPositiveHeightException;
import tablesExceptions.OutOfTableException;

import dataStructures.SegmentTree;

/**
 * SingleColumnTable creates a table with a single column and rows of different
 * heights. Operations implemented are, updating a row height and querying the
 * index of a cell at a certain height.
 * 
 * This implementation assumes that both operations are equally probable to be
 * called, a UI application would need both operations equally.
 * 
 * The class uses a segment tree underneath to handle both operations
 * efficiently with a space of O(n), where n is the number of the rows.
 * 
 * Both operations run in O(log n), where n is the number of the rows.
 * 
 * Zero and negative row heights are not allowed and throw exceptions.
 */
public class SingleColumnTable {

	/*
	 * An instance of the SegmentTree Class that holds the rows heights.
	 */
	private SegmentTree segmentTree;

	/**
	 * Class constructor specifying the array of heights of each row.
	 * 
	 * @throws NonPositiveHeightException
	 *             if a non positive height occurred
	 */
	public SingleColumnTable(int[] heights) throws NonPositiveHeightException {
		
		segmentTree = new SegmentTree(heights);
	}

	/**
	 * Class constructor specifying a number of rows with equal heights.
	 * 
	 * @throws NonPositiveHeightException
	 *             if a non positive height was supplied
	 */
	public SingleColumnTable(int height, int numRows)
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

		segmentTree.updateSegment(index, height);
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

		return segmentTree.queryHeight(point);
	}

	/**
	 * Returns the current total height of the Single Column Table.
	 * 
	 * @return table height
	 */
	public int getTableHeight() {

		return segmentTree.getTreeSum();
	}

	/**
	 * Returns an integer array with the heights of the rows.
	 * 
	 * @return rows heights
	 */
	public int[] getHeights() {

		return segmentTree.getElements();
	}

	public String toString() {

		return segmentTree.elementsToString();
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
