package RotateString;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args){
        System.out.println(rotateString("abcde", "cdeab"));

    } 
    private static boolean rotateString(String s , String goal){
        String temp = s;
        for(int i = 0 ; i < s.length() ; i++){
            if(temp.equals(goal)){
                return true;
            }
            temp = rotate(temp);
        }
        return false;
    }
    private static String rotate(String s){
        Queue<Character> q = new LinkedList<>();
        for(char c : s.toCharArray()){
            q.offer(c);
        }
        q.offer(q.remove());
        StringBuilder ans = new StringBuilder(); 
        while(!q.isEmpty()){
            ans.append(q.poll());
        }
        return ans.toString();
    }
}
