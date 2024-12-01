package ValidPerfectSquare;

public class Solution {
    public static void main(String[] args){
        System.out.println(isPerfectSquare(121));
    } 
    private static boolean isPerfectSquare(int num){
        int low = 1;
        int high = num -1;
        // int condition = num /10;
        // if(num == 5 || condition == 2 || condition == 3 || condition == 7 || condition == 8){
        //     return false;
        // }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(num / mid == mid){
                return true;
            }
            else if (num / mid > mid) {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
}
