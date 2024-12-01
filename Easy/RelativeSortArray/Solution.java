package RelativeSortArray;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Solution{
    public static void main(String[] args){
        int[] arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
        int[] arr2 = {2,42,38,0,43,21};

        printArr(relativeSortArray(arr1, arr2));
        printArr(relativeSortArrayCounting(arr1, arr2));
    }
    private static int[] relativeSortArrayCounting(int[] arr1, int[] arr2){
        int[] count = new int[1001];
        for(int i : arr1){
            count[i]++; 
        }
        int i = 0;
        for(int j : arr2){
            while(count[j] --> 0){
                arr1[i++] = j;
            }
        }
        for(int x = 0 ; x < count.length ; x ++){
            while(count[x] --> 0){
                arr1[i++] = x;
            }
        }

        return arr1;
    }
    private static int[] relativeSortArray(int[] arr1, int[] arr2){
        HashMap<Integer, Integer> map  = new HashMap<>();
        for (int i : arr1) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map .put(i, 0);
            }
        }
        int[] ans = new int[arr1.length];
        int k = 0;
        for (int j = 0; j < arr2.length; j++) {
            int num = arr2[j];
            while (map.get(num) >= 0) {
                ans[k] = arr2[j];
                map .put(num,map.get(num) - 1);
                k++;
            }
            if(map.get(num) == -1){
                map.remove(num);
            }
        }
        ArrayList<Integer> unorderedList = new ArrayList<>();
        for(int i : map.keySet()){
            while (map.get(i) >= 0) {
                unorderedList.add(i);
                map.put(i, map.get(i) - 1);
            }
        }
        Integer[] result = new Integer[unorderedList.size()];
        result = unorderedList.toArray(result);
        Arrays.sort(result);
        for(int i : result){
            ans[k] = i;
            k++;
        }
        return ans;
    } 
    private static void printArr(int[] arr){
        for(int i : arr){
            System.out.print(i  + " , ");
        }
        System.out.println();
    }
}