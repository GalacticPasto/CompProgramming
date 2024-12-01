package LongestCommonPrefix;

public class Solution {
    public static void main(String[]args){
        Trie t = new Trie();
        String [] characters = {"flower","flow","flight"};
        System.out.println(t.searchCommonPrefix(characters));
        
    } 
}
