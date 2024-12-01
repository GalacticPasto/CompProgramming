package SpecialArrayWithXElementsGreaterThanOrEqualX;

public class Solution{
    public static void main(String[] args){
        int[] nums = {3,6,7,7,0};
        System.out.println(specialArray(nums));
    }
    public static int specialArray(int[] nums){
      int min = 0;
        for(int i : nums){
            if(i != 0){
                min = Math.min(i,min);
            }
        }
        int count = 0;
        for(int i : nums){
            if(i != 0 && i >= min){
                count++;
            }
        }
        return (count < min)? count:-1;
    }
}
