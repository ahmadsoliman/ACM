package unitTests;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

import java.util.Random;

import org.junit.BeforeClass;
import org.junit.Test;

import tables.SingleColumnTableRareResizes;
import tablesExceptions.IndexOutOfTableBoundsException;
import tablesExceptions.NonPositiveHeightException;
import tablesExceptions.OutOfTableException;
import tablesExceptions.TablesException;

/*
 * Tests the correctness of the SingleColumnTableRareResizes Class,
 * against simple examples, edge cases and a brute force checker.
 * 
 */
public class SingleColumnTableRareResizesTests {
	private static SingleColumnTableRareResizes sct;
	private static int testHeights[] = new int[] { 2, 1, 3, 5, 5, 4, 9 };

	@BeforeClass
	public static void testSetup() {
		try {
			sct = new SingleColumnTableRareResizes(testHeights);
		} catch (NonPositiveHeightException e) {
		}
	}

	@Test
	public void testInitialization() {
		assertArrayEquals(testHeights, sct.getHeights());
	}

	@Test
	public void testLeftBound() {
		try {
			assertEquals(0, sct.findCell(0));
		} catch (OutOfTableException e) {
		}
	}

	@Test
	public void testAllCells() {
		int sum = 0;
		for (int i = 0; i < testHeights.length; i++) {
			for (int j = 1; j <= testHeights[i]; j++) {
				try {
					assertEquals(i, sct.findCell(sum + j));
				} catch (OutOfTableException e) {
				}
			}
			sum += testHeights[i];
		}
	}

	@Test
	public void testLeftOutOfBounds() {
		try {
			sct.findCell(-1);
			fail();
		} catch (OutOfTableException e) {
		}
	}

	@Test
	public void testRightOutOfBounds() {
		try {
			sct.findCell(30);
			fail();
		} catch (OutOfTableException e) {
		}
	}

	@Test
	public void testResize() {
		SingleColumnTableRareResizes sct2;
		try {
			sct2 = new SingleColumnTableRareResizes(testHeights);
			for (int i = 0; i < testHeights.length; i++) {
				sct2.resize(i, 5);
			}
			assertEquals(5 * testHeights.length, sct2.getTableHeight());
		} catch (TablesException e1) {
		}
	}

	@Test
	public void testResizeIndexOutOfBounds() {
		try {
			sct.resize(-5, 5);
			fail();
		} catch (IndexOutOfTableBoundsException e) {
		} catch (NonPositiveHeightException e) {
			fail();
		}
	}

	@Test
	public void testNegativeHeight() {
		try {
			new SingleColumnTableRareResizes(new int[] { 2, -1 });
			fail();
		} catch (NonPositiveHeightException e) {
		}
	}

	@Test
	public void testResizeNegativeHeight() {
		try {
			sct.resize(0, -2);
			fail();
		} catch (IndexOutOfTableBoundsException e) {
			fail();
		} catch (NonPositiveHeightException e) {
		}
	}

	@Test(timeout = 1000)
	/*
	 * Tests all table sizes from 1 to 100 with random heights, all tested for
	 * correctness of the findCell query before and after a resize.
	 */
	public void testDifferentSizedColumns() {
		Random rand = new Random();
		for (int i = 1; i <= 100; i++) {
			int heights[] = new int[i];
			for (int j = 0; j < heights.length; j++) {
				heights[j] = rand.nextInt(100) + 1;
			}

			try {
				SingleColumnTableRareResizes sct2 = new SingleColumnTableRareResizes(
						heights);

				int sum = 0;
				for (int j = 0; j < heights.length; j++) {
					for (int k = 1; k <= heights[j]; k++) {
						try {
							assertEquals(j, sct2.findCell(sum + k));
						} catch (OutOfTableException e) {
						}
					}
					sum += heights[j];
				}

				int index = rand.nextInt(heights.length);
				int height = rand.nextInt(100);
				sct2.resize(index, height);
				heights[index] = height;

				sum = 0;
				for (int j = 0; j < heights.length; j++) {
					for (int k = 1; k <= heights[j]; k++) {
						try {
							assertEquals(j, sct2.findCell(sum + k));
						} catch (OutOfTableException e) {
						}
					}
					sum += heights[j];
				}

			} catch (TablesException e1) {
			}
		}
	}

}
