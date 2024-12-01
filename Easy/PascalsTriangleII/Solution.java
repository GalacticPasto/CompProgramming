package PascalsTriangleII;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        getRowEasy(3);
    } 
    private static List<Integer> getRow(int rowIndex){
        List<List<Integer>> listOfList = new ArrayList<>();
        List<Integer> first = new ArrayList<>();
        first.add(1);
        listOfList.add(first);
        for(int i = 1 ; i <= rowIndex + 1;i++){
            List<Integer> prev = listOfList.get(i-1); 
            List<Integer> curr = new ArrayList<>();
            curr.add(1);
            for(int j = 1 ; j < i ; j++){
                curr.add(prev.get(j-1) + prev.get(j));
            }
            curr.add(1);
            listOfList.add(curr);
        }
        return listOfList.get(rowIndex);
    }
    private static void printList(List<Integer> ans){
        for(int i : ans){
            System.out.print(i);
        }
        System.out.println();
    }
    private static void getRowEasy(int rowIndex){
        int[] row = new int[rowIndex+1]; 
        Arrays.fill(row,0);
        row[0] = 1;
        for(int i = 1 ; i <= rowIndex; i++){
            for(int j = i ; j > 0; j-- ){
                row[j] = row[j-1] + row[j];
            }
        }
        for(int i : row){
            System.out.print(i);
        }
    } 
}
