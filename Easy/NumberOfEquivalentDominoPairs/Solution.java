package NumberOfEquivalentDominoPairs;


public class Solution {
    public static void main(String[] args){
        int[][]dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2},{1,2}};
        System.out.println(numberOfEquivalentDominoPairs(dominoes));
    } 
    private static int numberOfEquivalentDominoPairs(int[][] dominoes){
        int[] count = new int[100];
        int pairsCount = 0;
        for(int[] row : dominoes){
            int up = Math.min(row[0],row[1]);
            int down= Math.max(row[0],row[1]);
            
            pairsCount +=count[up * 10 + down]++;
        }
        return pairsCount;
    }
}
