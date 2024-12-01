package DetectPatternOfLengthMRepeatedKorMoreTimes;


public class Solution {
    public static void main(String[] args){
        int[] nums = {2,2,1,2,2,1,1,1,2,1};
        System.out.println(conatainsPattern(nums, 2, 2));
    }
    private static boolean conatainsPattern(int[] arr,int m, int k){
        int count = 0;
        for(int i = 0 ; i < arr.length - m ; i++){
            if(arr[i] == arr[i+m]){
                count++;
            }
            else{
                count = 0;
            }
            if(count ==m*(k-1)){
                return true;
            }
        }
        return false;
    }
}
