package NumberOfStepsToReduceNumberToZero;

public class Solution {
    public static void main(String[] args){
        System.out.println(numberOfSteps(14));
    } 
    private static int numberOfSteps(int num){
        int temp = num;
        int count = 0;
        while(temp > 0){
            if((temp & 1) == 0){
                temp = temp >> 1;
            }
            else{
                temp -= 1;
            }
            count++;
        }
        return count;
    }
}
