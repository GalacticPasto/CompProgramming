package ReverseBits;

public class Solution {
    public static void main(String[] args) {
        System.out.println(reverseBits(4));
        ithBitSet(0, 0);
    }

    private static int reverseBits(int n) {
        int ans = 0 ;  
        for(int i =1 ; i <= 32 ; i++){
            int ithBit = n & 1;
            int temp = ithBit <<(32-i);
            ans |= temp;
            n >>=1;
        }
        return ans;
    }
    private static void ithBitSet(int n , int position){
        if ((n & (1<<(position - 1))) != 0) {
            System.out.println("true");
        }
        else{
            System.out.println("false");
        }
    }
}
