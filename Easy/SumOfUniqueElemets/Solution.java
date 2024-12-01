package SumOfUniqueElemets;

import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {

    } 

    private static int sumOfUnique(int[] nums){
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i : nums){
            map.put(i, map.getOrDefault(i, 0)+1);
        }
        int sum = 0;
        for(int i : map.keySet()){
            if(map.get(i) == 0){
                sum+= i;
            }
        }
        return sum;
    }
}
