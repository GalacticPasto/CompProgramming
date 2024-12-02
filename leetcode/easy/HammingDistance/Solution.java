package HammingDistance;

public class Solution {
    public static void main(String[] args){
        System.out.println(hammingDistance(3,1));
    } 
    private static int hammingDistance(int x , int y){
        int xOr = (x ^ y);
        int count =0;
        while(xOr > 0){
            count++;
            xOr = xOr &(xOr -1);
        }
        return count;
    }
}

