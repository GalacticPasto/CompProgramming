package SingleNumber;

public class Solution {
    public static void main(String []args){
        int[] array = {4,1,2,1,2};
        singleNumber(array);
    } 
    public static int singleNumber(int[]array){
        int ans = 0;
        for(int i = 0 ; i < array.length ; i++){
            ans = ans^array[i];    
            System.out.println(ans + " " + i);
        }
        return ans;
    }
}
