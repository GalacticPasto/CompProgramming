package IntersectionOfTwoArrays;

import java.util.ArrayList;
import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        int[] nums1 = {4,9,5};
        int[] nums2 = {9,4,9,8,4};
        printArray(intersectionPointers(nums1, nums2));
    } 
    private static int[] intersection(int[] nums1, int[] nums2){
        ArrayList<Integer> list = new ArrayList<>();
        Hashtable<Integer, Integer> table = new Hashtable<>();
        for(int i : nums1){
            if(!table.containsKey(i)){
                table.put(i, 0);
            }
        }
        for(int j : nums2){
            if(table.containsKey(j)){
                if(!list.contains(j)){
                list.add(j);
                }
            }
        }
        int[] ans = new int[list.size()];
        for(int i = 0 ; i < list.size() ;i++){
            ans[i] = list.get(i);
        }
        return ans;
    }
    private static int[] intersectionPointers(int[] nums1, int[] nums2){
        
        ArrayList<Integer> list = new ArrayList<>();
        int i = 0 ; 
        int j = 0;
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] == nums2[j]){
                list.add(nums1[i]);
                i++;
            }
            j++;
        }
        int[] ans = new int[list.size()];
        for(int k = 0 ; k < list.size() ;k++){
            ans[k] = list.get(k);
        }
        return ans;

    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i);
        }
        System.out.println();
    }
}
