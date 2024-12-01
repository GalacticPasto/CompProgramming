package ToePlitzMatrix;

public class Solution {
    public static void main(String[] args){
        isToePlitzMatrix(null);

    } 
    private static boolean isToePlitzMatrix(int[][] matrix){
        int row = matrix.length;
        int column = matrix[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if(matrix[i][j] == matrix[i + 1][j+1]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
}
