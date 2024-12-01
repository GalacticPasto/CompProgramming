package RangeAdditionII;

public class Solution {
    public static void main(String[] args){
        int[][] ops = {{18,35},{11,36},{18,23},{20,16},{12,18},{2,37},{15,36},{17,37},{16,37},{2,13},{6,37},{10,24},{4,33},{8,28},{9,26},{19,38},{2,19}};
        System.out.println(maxCountEfficent(20,40, ops));
        System.out.println();
        System.out.println(maxCount(20, 40, ops));
    }
    private static int maxCountEfficent(int m , int n , int[][] ops){
        if(ops.length == 0){
            return m * n;
        }
        else if(ops.length == 1){
            return ops[0][0] * ops[0][1];    
        }

       

        int[][] ans = new int[10][10];
        int max = Integer.MIN_VALUE;
        for(int[] row : ops){
            max = fill(ans, row,max);
        }

        printArr(ans);
        int counter = 0;
        for(int[] row : ans){
            for(int i : row ){
                if(i == max){
                    counter++;
                }
            }
        }
        return counter;
    }
    private static int fill(int[][] ans,int[] row,int max){ 
        int rowRange = row[0];
        int columnRange = row[1];
        if(rowRange > 10) rowRange =10;
        if(columnRange > 10) columnRange = 10;
        for (int i = 0; i < rowRange; i++) {
            for (int j = 0; j < columnRange; j++) {
                ans[i][j] += 1;
                max = Math.max(ans[i][j], max);
            }
        }
        return max;
    }
    private static int maxCount(int m , int n , int[][] ops){
        int[][] mat = new int[m][n];
        
        int max = 0;
        for(int[] row : ops){
            max = add(mat,row,max);
        }
        printArr(mat);
        System.out.println();
        int counter = 0;
        for(int i = 0; i < mat.length;i++){
            for(int j = 0 ; j < mat[0].length; j++){
                if(mat[i][j]== max){
                    counter++;
                }
            }
        }
        return counter;
    }    
    private static int add(int[][] mat , int[] range, int max){
        int rowRange = range[0]-1;
        int columnRange = range[1]-1;
        for(int i = 0; i <= rowRange ;i++){
            for(int j = 0 ; j <= columnRange ; j++){
                mat[i][j] += 1;
                max = Math.max(mat[i][j],max);
            }
        }
        return max;
    }
    private static void printArr(int[][] mat){
        for(int[] row : mat){
            for(int i : row){
                System.out.print(i + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
