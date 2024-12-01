package NumberComplement;

public class Solution {
    public static void main(String[] args){
        System.out.println(findComplement(5));

    }
    private static int findComplement(int num){
        int ans = 0;
        int temp = num;
        int pointer =1;
        while (temp > 0) {
            if ((temp & 1) ==0) {
                ans = ans | pointer;
            }
            pointer <<= 1;
            temp >>= 1;
        }
        return ans;
    }
}
