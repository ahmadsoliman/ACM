package images;

public class VisualizationsAmr {
	
	//0- ZX front 1- ZY right 2- ZX back 3- ZY left
	public static void runThroughPlane(byte[][][] array, int plane) {
		int size = array[0][0].length;
		
		if (plane == 0) {
			//1
			array[5][0][0] = (byte)0xff;
			//2
			array[0][0][0] = (byte)0xff;
			array[1][0][0] = (byte)0xff;

			array[4][1][0] = (byte)0xff;
			array[5][1][1] = (byte)0xff;
			//3
			array[4][0][0] = (byte)0xff;
			array[6][0][0] = (byte)0xff;
			array[4][0][1] = (byte)0xff;
			array[5][0][2] = (byte)0xff;
			
			array[2][1][0] = (byte)0xff;
			array[6][1][0] = (byte)0xff;
			array[0][1][1] = (byte)0xff;
			array[1][1][1] = (byte)0xff;
			//4
			array[2][0][0] = (byte)0xff;
			array[3][0][0] = (byte)0xff;
			array[4][0][0] = (byte)0xff;
			array[5][0][0] = (byte)0xff;
			array[7][0][0] = (byte)0xff;
			array[2][0][1] = (byte)0xff;
			array[6][0][1] = (byte)0xff;
			array[0][0][2] = (byte)0xff;
			array[1][0][2] = (byte)0xff;
			
			array[2][1][0] = (byte)0xff;
			array[3][1][0] = (byte)0xff;
			array[4][1][0] = (byte)0xff;
			array[5][1][0] = (byte)0xff;
			array[7][1][0] = (byte)0xff;
			array[5][1][3] = (byte)0xff;
			array[6][1][1] = (byte)0xff;
			array[4][1][1] = (byte)0xff;
			array[4][1][2] = (byte)0xff;
			//5
			array[1][0][0] = (byte)0xff;
			array[6][0][0] = (byte)0xff;
			array[2][0][1] = (byte)0xff;
			array[3][0][1] = (byte)0xff;
			array[4][0][1] = (byte)0xff;
			array[5][0][1] = (byte)0xff;
			array[7][0][1] = (byte)0xff;
			array[4][0][2] = (byte)0xff;
			array[6][0][2] = (byte)0xff;
			array[4][0][3] = (byte)0xff;
			array[5][0][4] = (byte)0xff;
			
			array[4][1][0] = (byte)0xff;
			array[6][1][0] = (byte)0xff;
			array[2][1][1] = (byte)0xff;
			array[3][1][1] = (byte)0xff;
			array[4][1][1] = (byte)0xff;
			array[5][1][1] = (byte)0xff;
			array[7][1][1] = (byte)0xff;
			array[0][1][4] = (byte)0xff;
			array[6][1][2] = (byte)0xff;
			array[1][1][3] = (byte)0xff;
			array[2][1][2] = (byte)0xff;
			//6
			
			
			
			
			
		}else if (plane == 1) {
			
		}else if (plane == 2) {
			
		}else if (plane == 3) {
			
		}
	}
	
}
