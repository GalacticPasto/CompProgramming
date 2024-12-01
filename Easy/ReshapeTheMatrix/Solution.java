package ReshapeTheMatrix;

public class Solution {
    public static void main(String[] args){
        int[][] mat = {{1,2}, {3,4}};
        printMat(matrixReshape(mat, 4, 1));
    } 
    private static int[][] matrixReshape(int[][] mat , int r , int c){
        int row = mat.length;
        int rowLen = mat[0].length; 
        if(r * c != row * rowLen){
            return mat;
        }
        int [][]ans  = new int[r][c];
        int ansRow = 0;
        int ansColum= 0;
        for(int j = 0 ; j < row; j++){
            for(int i = 0 ; i < rowLen ; i++){
                ans[ansRow][ansColum] = mat[j][i];
                ansColum++;
                if (ansColum >= c) {
                    ansColum = 0;
                    ansRow++;
                }
            }
        }
        return ans;
    }
    private static void printMat(int[][] mat){
        for(int []row : mat){
            for(int i : row){
                System.out.print(i + " ");
            }
            System.out.println();
        }

    }
}
