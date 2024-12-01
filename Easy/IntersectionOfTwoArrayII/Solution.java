package IntersectionOfTwoArrayII;

import java.util.ArrayList;
import java.util.HashMap;

public class Solution {
   public static void main(String []args){
        int[] nums1 = {4,9,5};
        int[] nums2 ={9,4,9,8,4}; 
        printArray(intersect(nums1, nums2));
   } 
   private static int[] intersect(int[] nums1 , int[] nums2){
        HashMap<Integer,Integer> map = new HashMap<>(); 
        for(int i : nums1){
            map.put(i,map.getOrDefault(i,0)+1);
        }
        ArrayList<Integer> ans = new ArrayList<>(); 
        for(int j : nums2){
            if(map.containsKey(j) && map.get(j)> 0){
                ans.add(j);
                map.put(j,map.get(j)-1);
            }
        }
        int[] answer = new int[ans.size()];
        for(int k = 0 ; k < ans.size(); k++){
            answer[k] = ans.get(k);
        }
    return  answer;
   }
   private static void printArray(int[] array){
        for(int i : array){
            System.out.println(i);
        }
   }
}
