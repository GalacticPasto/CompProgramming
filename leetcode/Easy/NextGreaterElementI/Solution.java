package NextGreaterElementI;

import java.util.Hashtable;
import java.util.Stack;

public class Solution {
    public static void main(String[] args){
        int[] nums1 = {4,1,2};
        int[] nums2 = {1,3,4,2};
        nextGreaterElementI(nums1, nums2);
    } 
    private static int[] nextGreaterElementI (int[] nums1, int[] nums2){
        int[] ans = new int[nums1.length];
        Stack<Integer> mono = new Stack<>();
        Hashtable<Integer , Integer> table = new Hashtable<>();
        for (int i = nums2.length - 1; i >= 0; i--) {
            while (!mono.isEmpty() && mono.peek() <= nums2[i]) {
                mono.pop();
            }
            table.put(nums2[i],mono.isEmpty() ? -1 : mono.peek());
            mono.push(nums2[i]);
        }
        for(int i = 0 ; i < nums1.length ;i++){
            ans[i] = table.get(nums1[i]);
        }
        return ans;
    }
}
