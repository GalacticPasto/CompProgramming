package WordBreak;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Solution {
    public static void main(String[] args){
        List<String> wordDict = new ArrayList<>();
        wordDict.add("my");
        wordDict.add("pen");
        System.out.println(wordBreak("mypen", wordDict));
    }    
    private static boolean wordBreak(String s, List<String> wordDict){
        int n = s.length();
        boolean[][] table = new boolean[n+1][n+1];
        HashSet<String> set = new HashSet<>();

        for(String jsjs : wordDict){
            set.add(jsjs);
        }

        for(int i =1 ; i <= n ; i++){
            for(int j = 0 ; j <= n ; j++){
                int k = i + j ;
                String sub = "";
                if(k <= n){
                    sub = s.substring(j, k);
                }
                if(j == k){
                    table[j][k] = true;
                }else if(set.contains(sub) && k <= n){
                    table[j][k] = true;
                }
                else if(k <= n){
                    table[j][k] = false;
                }
            }
        }
        
        printMat(table);
        return false;
    }
    private static void printMat(boolean[][] table){
        for(boolean[] row : table){
            for(boolean t : row){
                System.out.print(t + " ");
            }
            System.out.println();
        }
    }
}
