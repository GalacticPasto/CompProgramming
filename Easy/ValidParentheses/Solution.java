package ValidParentheses;

import java.util.Stack;

public class Solution {

    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            char c = arr[i];
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c);
            }
            else{
                if(stack.isEmpty()){
                    return false;
                }
                else{
                    char top = stack.peek();
                    if(c == '}' && top == '{' || c == ']' && top == '[' ||c == ')' && top == '('){
                        stack.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
                
        }
        return stack.isEmpty();
    }
    public static void main(String [] args){
        String s ="(])"; 
        System.out.println(isValid(s));
    }
}
