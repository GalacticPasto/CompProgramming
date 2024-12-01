package CanPlaceFlowers;

public class Solution {
    public static void main(String[] args){


    } 
    private static boolean canPlaceFlowers(int[] flowerbed, int n){
        int count = 0;
        for(int i = 0 ; i < flowerbed.length; i++){
            if(flowerbed[i] == 0){
                boolean emptyFlowerbedLeft = flowerbed[i-1] == 0;
                boolean emptyFlowerbedRight = flowerbed[i+1] == 0;
                if(emptyFlowerbedLeft && emptyFlowerbedRight){
                    flowerbed[i] = 1;
                    count ++;
                }
            } 
        }
        return count <= n;
    }

}
