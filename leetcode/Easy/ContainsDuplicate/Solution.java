package ContainsDuplicate;

import java.util.Hashtable;

public class Solution {
   public static void main(String [] args){
        int[] nums = {2,2,2,2,2,2,2,2};
        System.out.println(containsDuplicate(nums));
   } 
   private static boolean containsDuplicate(int[] nums){
    Hashtable<Integer,Integer> table = new Hashtable<>();
    for(int i = 0 ; i < nums.length;i++){
        if(table.containsKey(nums[i])){
            table.put(nums[i],table.get(nums[i]) + 1);
            continue;
        }
        table.put(nums[i],0);
    }
    for(int i = 0 ; i < nums.length ; i++){
        if(table.get(nums[i]) >= 1){
            return true;
        }
    }
    return false;
   }
}

