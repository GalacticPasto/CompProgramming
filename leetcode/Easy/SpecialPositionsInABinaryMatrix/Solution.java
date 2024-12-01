package SpecialPositionsInABinaryMatrix;

public class Solution {
   public static void main(String[]args){
        int[][] mat = {{0,0,0,1},{1,0,0,0},{0,1,1,0},{0,0,0,0}};
        printMat(mat);
        System.out.println();
        System.out.println(numSpecial(mat));
   } 
   private static int numSpecial(int[][] mat){

    int m = mat.length ;
    int n = mat[0].length;
    int ans = 0;

    for(int i = 0 ; i < m ; i++){
        boolean alreadyFound = false;
        for(int j = 0 ; j < n ; j++){
            if(!alreadyFound && mat[i][j] == 1){
                ans+= isSpecial(mat, i, j);
                alreadyFound = true;
                i++;
            }
        }
    }

    return ans;
   }
   private static int isSpecial(int[][] mat, int row, int column){
        int noOfOnesCurrRow = 0;
        for(int i = 0 ; i < mat[0].length ;i++){
            if(mat[row][i] == 1){
                noOfOnesCurrRow++;
            }
        }
        int noOfOnesCurrColumn = 0;
        for(int i = 0 ; i < mat.length ;i++){
            if(mat[i][column] == 1){
                noOfOnesCurrColumn++;
            }
        }
        if(noOfOnesCurrColumn > 1 || noOfOnesCurrRow > 1){
            return 0;
        }
        return (noOfOnesCurrColumn == noOfOnesCurrRow) ? 1 : 0;
   } 
   private static void printMat(int[][] mat){
        for(int i = 0 ; i < mat.length ; i++){
            System.out.println();
            for(int j = 0 ; j < mat[0].length ;j++){
                System.out.print(mat[i][j] + " ");
            }
        }
   }
}
