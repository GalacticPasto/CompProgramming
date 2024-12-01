package ThirdMaximumNumber;
public class Solution {
    public static void main(String[] args){
        int[] nums = {2,2,3,1};
        System.out.println(thirdMax(nums));
    }
    private static int thirdMax(int[] nums){
        int firstMax = 0;
        int secondMax = 0;
        int thirdMax = 0;
        for(int i : nums){
            if(firstMax == i || secondMax == i || thirdMax == i){
                continue;
            }
            if(i >= firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = i;
            }
            else if(i >= secondMax){
                thirdMax = secondMax;
                secondMax = i;
            }
            else if(i >= thirdMax){
                thirdMax = i;
            }
        }
        if(thirdMax == Integer.MIN_VALUE){
            return firstMax;
        }
        return thirdMax;
    }
}
