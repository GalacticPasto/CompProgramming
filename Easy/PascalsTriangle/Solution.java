package PascalsTriangle;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        printList(generate(5));
    }

    private static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> firstRow = new ArrayList<>(); 
        firstRow.add(1);
        list.add(firstRow);
        for(int i =1 ; i < numRows ; i++){
            List<Integer> prevRow  = list.get(i-1);
            List<Integer> newRow = new ArrayList<>();
            newRow.add(1);
            for(int j = 1 ; j<i; j++){
                newRow.add(prevRow.get(j-1) + prevRow.get(j));
            }
            newRow.add(1);
            list.add(newRow);
        }
        return list;
    }
    private static void printList(List<List<Integer>> list){
        for(int i = 0 ; i < list.size(); i++){
            List<Integer> h = list.get(i);
            for(Integer j: h ){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
