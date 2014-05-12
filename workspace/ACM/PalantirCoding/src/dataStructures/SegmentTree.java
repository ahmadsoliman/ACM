package dataStructures;

import java.util.Arrays;

import tablesExceptions.IndexOutOfTableBoundsException;
import tablesExceptions.NonPositiveHeightException;
import tablesExceptions.OutOfTableException;

/**
 * A segment tree implementation represented in an array where each node holds
 * only the sum of the leaves in its range.
 * 
 * The root is saved at index 1, and each node with index i has a left child
 * saved at 2*i and a right child at 2*i+1.
 * 
 * It uses exactly n+2^ceil(log2(n)) memory, where n is the number of elements
 * stored.
 */
public class SegmentTree {

	/*
	 * The array which holds the segment tree sum values, including leaves which
	 * holds only an element value.
	 */
	private int segment[];
	private int numberOfElements; // The number of elements in the tree
	private int treeSize; // The number of inner nodes in the tree

	/**
	 * Class constructor specifying the elements in the tree
	 */
	public SegmentTree(int elements[]) throws NonPositiveHeightException {

		numberOfElements = elements.length;
		segment = new int[getProperSegmentSize(numberOfElements)];
		treeSize = segment.length - numberOfElements;

		// place the elements at the leaves
		for (int i = 0, j = treeSize; i < numberOfElements; i++, j++) {
			if (elements[i] < 1) {
				throw new NonPositiveHeightException(elements[i]);
			}
			segment[j] = elements[i];
		}

		// update all the inner nodes level by level from the bottom upwards
		for (int i = treeSize - 1; i > 0; i--) {
			updateSegmentElement(i);
		}
	}

	/*
	 * Calculates 2^ceil(log2(n))+n, the exact number of nodes needed in the
	 * segment tree to avoid extra memory usage.
	 */
	private int getProperSegmentSize(int numberOfElements) {
		
		int segmentSize = 1;
		while (segmentSize < numberOfElements) {
			segmentSize <<= 1;
		}
		
		segmentSize += numberOfElements;
		return segmentSize;
	}

	/**
	 * Updates a single element at index with new value.
	 * 
	 * Iteratively updates all the ancestors of the changed element up to the
	 * root.
	 */
	public void updateSegment(int index, int value)
			throws IndexOutOfTableBoundsException, NonPositiveHeightException {

		if (index < 0 || index >= numberOfElements) {
			throw new IndexOutOfTableBoundsException(index);
		}

		if (value < 1) {
			throw new NonPositiveHeightException(value);
		}

		// element index in the segment tree
		int segmentIndex = index + treeSize;

		// update the element with its new value
		segment[segmentIndex] = value;

		// update every ancestor of the element until the root
		segmentIndex >>= 1;
		while (segmentIndex > 0) {
			updateSegmentElement(segmentIndex);

			// traverse to parent
			segmentIndex >>= 1;
		}
	}

	/*
	 * A helper method that updates a single inner node with the already set
	 * values of its children.
	 */
	private void updateSegmentElement(int index) {

		int leftChildIndex = index << 1;
		int rightChildIndex = leftChildIndex + 1;

		int leftChild = 0, rightChild = 0;

		// check for out of bounds
		if (leftChildIndex < segment.length) {
			leftChild = segment[leftChildIndex];
		}

		if (rightChildIndex < segment.length) {
			rightChild = segment[rightChildIndex];
		}

		segment[index] = leftChild + rightChild;
	}

	/**
	 * Customized query to find the index of the cell at which the point occurs.
	 * 
	 * Through traversing down the tree trying to find where the point occurs,
	 * and choosing between left and right children and updating the remaining
	 * height.
	 * 
	 */
	public int queryHeight(int point) throws OutOfTableException {

		if (point < 0 || point > getTreeSum()) {
			throw new OutOfTableException(point);
		}

		// current index in the tree starting at the root
		int index = 1;

		// traverse down unless current node is a leaf
		while (index < treeSize) {
			int leftChildIndex = index << 1;

			int leftChild = point;
			if (leftChildIndex < segment.length) {
				leftChild = segment[leftChildIndex];
			}

			if (point > leftChild) {
				// traverse to right child
				
				point -= leftChild;
				index = (index << 1) + 1;
			} else {
				// traverse to left child
				
				index <<= 1;
			}
		}
		// index of the element is its count in the leaves of the tree
		return index - treeSize;
	}

	/**
	 * @return the sum of the whole tree saved in the root
	 */
	public int getTreeSum() {
		return segment[1];
	}

	/**
	 * @return the current elements saved in the tree
	 */
	public int[] getElements() {

		int heights[] = new int[numberOfElements];

		for (int i = 0, j = segment.length - numberOfElements; i < heights.length; i++, j++) {
			heights[i] = segment[j];
		}

		return heights;
	}

	public String toString() {
		return Arrays.toString(segment);
	}

	public String elementsToString() {
		return Arrays.toString(getElements());
	}

}
