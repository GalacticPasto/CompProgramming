package DiStringMatch;

public class Solution {
    public static void main(String[] args){
        printArray(diStringMatch("IDID")); 

    } 
    private static int[] diStringMatch(String s){
        int[] ans = new int[s.length() + 1];
        int max = s.length(); 
        int low = 0;
        for(int i = 0 ; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == 'I'){
                ans[i] = low;
                low ++;
            }
            else{
                ans[i] = max;
                max--;
            }
        }
        char c = s.charAt(s.length()-1);
        if(c == 'I'){
            ans[ans.length-1] = low;
        }
        else{
            ans[ans.length-1] = max;
        }
        return ans;
    }
    private static void printArray(int[] arr){
        for(int i : arr){
            System.out.print(i);
        }
        System.out.println();
    }
}
