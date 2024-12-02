package ContainerWithMostWater;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,8,6,2,5,4,8,3,7};
        System.out.println(maxArea(nums));
    } 
    private static int maxArea(int[] height){
        int n = height.length;
        int maxArea = 0;      
        int high = n-1;
        for(int i = 0 ; i < n ; i++){
            int area = 0;
            if (height[i] > height[high]) {
                area = height[high] * (high - i);
                high--;
            }
            else{
                area = height[i] *(high-i);
            }
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }
}
