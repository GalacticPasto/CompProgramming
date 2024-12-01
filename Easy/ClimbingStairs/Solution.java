package ClimbingStairs;

public class Solution{

    public static  int climbStairs(int n){
        int[] memoiazation = new int[n+1];
        memoiazation[0]= 1;
        memoiazation[1] = 1;
        for(int i = 2 ; i < memoiazation.length ; i++){
            memoiazation[i] = memoiazation[i-1] + memoiazation[i-2];
        }
        return memoiazation[n];
    }

    public static void main(String []args){
        System.out.println(climbStairs(5));        
    }

}