package ArrangingCoins;

public class Solution {
    public static void main(String[] args){
        System.out.println(arrangeCoins(1));
    }
    private static int arrangeCoins(int n){
        int i = 0;
        int temp=n;
        int ans = 0;
        while(temp >= 0){
            temp -=i;
            if(temp >= 0){
                ans= i;
            }
            i++;
        } 
        return ans;
    }
}
