package FindAllDisappearedNumbers;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args){
        int [] nums = {4,3,2,7,8,2,3,1};
        printList(findAllDisappearedNumbers(nums));
    } 
    private static List<Integer> findAllDisappearedNumbers(int[] nums){
        int n = nums.length;
        for(int i = 0 ; i < n ; i++){
            int num = Math.abs(nums[i])-1;
            if(nums[num] <= 0){
                continue;
            }
            nums[num] *=-1;
        }
        List<Integer> list = new ArrayList<>();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
               list.add(i+1);  
            }
        }
       return list; 
    }
    private static void printList(List<Integer> result){
        for(int i : result){
            System.out.print(i + " ");
        }
    }
}
