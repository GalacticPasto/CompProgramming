package SqrtX;

public class Solution {
    public static void main(String [] args){
        System.out.println(mySqrt(25));
    } 
    private static int mySqrt(int x){
        int low = 1;
        int high = x;
        int ans = 0; 
        while(low <= high){
            int mid = low +(high-low)/2;
            System.out.println(x/mid);
            if(x/mid == mid){
                return mid;
            }
            else if(x/mid > mid){
                low = mid +1;
            }
            else{
                high = mid -1;
                ans = mid;
            }
        }
        return ans;
    }
}
