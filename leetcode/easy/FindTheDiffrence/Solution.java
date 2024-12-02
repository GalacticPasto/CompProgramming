package FindTheDiffrence;

public class Solution {
    public static void main(String[] args){
        System.out.println(findTheDiffrence("abcd","abcde"));
    } 
    private static char findTheDiffrence(String s, String t){
        int indexS = 0;
        int indexT = 0;
        for(char c : s.toCharArray()){
            indexS += c -'a';
        }
        for(char c : t.toCharArray()){
            indexT += c -'a';
        }
        int ans =Math.abs(indexT - indexS) +'a';
        return (char)ans;
    }
}
