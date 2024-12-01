package Shift2DGrid;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args){
        int[][] mat = {{1,2,3},{4,5,6},{7,8,9}};
        shiftGrid(mat, 3);
    } 
    private static List<List<Integer>> shiftGrid(int[][] grid , int k){
        int m = grid.length;
        int n = grid[0].length;
        int[][] ans = new int[m][n];
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[0].length ; j++){
                int row = (i + (j + k) / n) % m;
                int column = (j + k) % n;
                ans[row][column] = grid[i][j];
            }
        }
        List<List<Integer>> list= new ArrayList<>();
        printArr(ans);
        for(int [] row : ans){
            List<Integer> lists = new ArrayList<>();
            for(int i : row){
                lists.add(i);
            }
            list.add(lists);
        }
        return list; 
    }
    private static void printArr(int[][]mat){
        for(int[] row : mat){
            for(int i : row){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
