package SummaryRanges;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args){
        int[] nums = {0,1,2,4,5,7};
        summaryRanges(nums);
    } 
    private static List<String> summaryRanges(int[] nums){
        List<String> ans = new ArrayList<>();
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.length; i++) {
            start = nums[i];
            while (i + 1 < nums.length && nums[i]+1 == nums[i+1]) {
                i++;
            }
            end = nums[i];
            if(start == end){
                ans.add(start + "");
            }
            else{
                ans.add(start + "->" + end);
            }
        }
        for(String i : ans){
            System.out.print(i + " ,");
        }
        return ans; 
    }
}
