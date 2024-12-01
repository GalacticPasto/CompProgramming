package TheKWeakestRowsInMatrix;

import java.util.PriorityQueue;

public class Solution {
    public static void main(String[] args) {
        int[][] mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
        printArray(kWeakestRows(mat, 3));
    }

    public static int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]);
        for(int i = 0 ; i < mat.length ; i++){
            int soldiers = 0;
            for(int j = 0 ; j < mat[0].length ; j++){
                if(mat[i][j] == 1){
                    soldiers++;
                }
                else{
                    break;
                }
            }
            pq.offer(new int[]{i,soldiers});
        }
        int[] ans = new int[k];
        for(int i = 0 ; i < k ; i++){
            ans[i] = pq.poll()[0];
        }
        return ans;        
    }
    private static void printArray(int[] ans){
        for(int i : ans){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
