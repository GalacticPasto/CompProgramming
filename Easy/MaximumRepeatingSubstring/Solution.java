package MaximumRepeatingSubstring;

public class Solution{
    public static void main(String[] args){
        System.out.println(maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba"));
    }
    private static int maxRepeating(String sequence, String word){
        int n = sequence.length();
        int m = word.length();
        int max = 0;
        for(int i = 0 ; i < n; i++){
            int cnt = 0; int k =0;
            for(int j = i ; j < n ; j++ ){
                if(sequence.charAt(j) == sequence.charAt(k)){
                    k++;
                }
                else {
                    break;
                }
                if(k == m){
                    k = 0;
                    cnt++;
                }
            }
            max = Math.max(cnt,max);
        }
        return max;
    }
        
}