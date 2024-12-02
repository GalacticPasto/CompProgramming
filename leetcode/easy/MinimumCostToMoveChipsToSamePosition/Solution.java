package MinimumCostToMoveChipsToSamePosition;

public class Solution {
    public static void main(String[] args){
        minCostToMoveChips(null);
    } 
    private static int minCostToMoveChips(int[] position){
        int odd = 0;
        int even = 0;
        for(int i : position){
            if((i & 1) == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even > odd){
            return odd;
        }
        else{
            return even;
        }
    }
}
