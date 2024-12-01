package ElementAppearingMoreThan25perInSortArr;

import java.util.HashMap;

public class Solution {
    public static void main(String[] args){
        int[] arr = {1,2,2,6,6,6,6,7,10};
        System.out.println(findSpecialInteger(arr));
    } 
    private static int findSpecialInteger(int[] arr){
        int percent = (int)(arr.length * (0.25))+1; 
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i : arr){
            map.put(i, map.getOrDefault(i, 0)+1);
            if(map.get(i) > percent){
                return i;
            }
        }
        return 0;
    }
}
