package MajorityElement;

import java.util.HashMap;

public class Solution {
    public static void main(String[]args){
        int[] nums = {3,2,3};
        System.out.println(majorityElementMoores(nums));
        majorityElement(nums);
    }
    private static int majorityElement(int[]nums){
        HashMap<Integer,Integer>hm = new HashMap<>();
        for(int i = 0 ; i < nums.length; i++){
            if(!hm.containsKey(nums[i])){
                hm.put(nums[i], 0);
            }
            if(hm.containsKey(nums[i])){
                hm.put(nums[i],hm.get(nums[i])+1);
            }
        }
        for(int i : nums){
            if(hm.get(i) > (nums.length/2)){
                return i;
            }
        }
    return 0;
    }
    private static int majorityElementMoores(int[] nums){
        int element = nums[0];
        int count = 1 ;
        for(int i = 1 ; i < nums.length ; i++){
            if(count==0){
                element = nums[i];
            }
            if(element != nums[i]){
                count--;
            }
            else{
                count++;
            }
        }
        return element;
    }
}
