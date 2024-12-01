package ReformatTheString;

import java.util.Stack;

public class Solution {
    public static void main(String[] args){

    } 
    private static String reformat(String s){
        Stack<Character> digits = new Stack<>();
        Stack<Character> alpha = new Stack<>();
        for(char c : s.toCharArray()){
            if((int)c >= 97 && (int)c <= 122){
                alpha.push(c);
            }else if((int) c >= 48 && (int) c <= 57){
                digits.push(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        if(digits.size() == alpha.size()){
            while(!digits.isEmpty() && !alpha.isEmpty()){
                sb.append(digits.pop());
                sb.append(alpha.pop());
            }
        }else if(digits.size() == alpha.size()-1){
            while(!digits.isEmpty() && !alpha.isEmpty()){
                sb.append(alpha.pop());
                sb.append(digits.pop());
            }
            sb.append(alpha.pop());
        }
        else if(digits.size()-1== alpha.size()){
            while(!digits.isEmpty() && !alpha.isEmpty()){
                sb.append(digits.pop());
                sb.append(alpha.pop());
            }
            sb.append(digits.pop());
        }
        else{
            return ""; 
        }
        return sb.reverse().toString();
    }
}
