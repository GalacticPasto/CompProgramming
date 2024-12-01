package NumberOfGoodPairs;

import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,1,1,1}; 
        System.out.println(numIdenticalParis(nums));

    }
    public static int numIdenticalParis(int[] nums) {
        Hashtable<Integer,Integer> table = new Hashtable<>();
        int pairs = 0;
        for(int i : nums){
            int similar = table.getOrDefault(i,0);
            pairs += similar;
            System.out.println(pairs);
            table.put(i,similar+1);
        }
        return pairs;
    }
}
