package ContainsDuplicateII;

import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        int[] table = {1,0,1,1};
        System.out.println(containsNearbyDuplicate(table,1));
    }  
    private static boolean containsNearbyDuplicate(int[] nums, int k){
        Hashtable<Integer,Integer> table = new Hashtable<>();
        for(int i = 0 ; i < nums.length ; i++){
            if(!table.containsKey(nums[i])){
                table.put(nums[i],i);
            }
            else{
                int tempIndx = table.get(nums[i]);
                if(Math.abs(tempIndx-i) <= k){
                    return true;
                }
                else{
                    table.put(nums[i],i);
                }
            }
        }
        return false;
    }
}
