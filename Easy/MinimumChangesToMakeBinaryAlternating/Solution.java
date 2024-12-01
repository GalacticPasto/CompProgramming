package MinimumChangesToMakeBinaryAlternating;

public class Solution{
    public static void main(String[] args){
        minOperations("asdbfasdf");
        System.out.println((int)'a');
        System.out.println((int)'z');
        System.out.println((int)'1');
        System.out.println((int)'9');
    }
    private static int minOperations(String s){
        char[] binary = s.toCharArray();
        int ten = 0;
        int zeroOne = 0;

        for(int i = 0 ; i < binary.length ; i++){
            if((i & 1) == 0 && binary[i] == '0'){
                ten++;
            }else if((i & 1) == 1 && binary[i] == '1'){
                ten++;
            }
        }
        for(int i = 0 ; i < binary.length ; i++){
            if ((i & 1) == 0 && binary[i] == '1') {
                zeroOne++;
            } else if ((i & 1) == 1 && binary[i] == '0') {
                zeroOne++;
            }
        }
        return Math.min(ten, zeroOne);
    }
}
