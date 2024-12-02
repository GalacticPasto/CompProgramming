package NumberOfStudentsUnableToEatLunch;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution {
    public static void main(String[] args){
        
    } 
    private static int countStudents(int[] students , int[] sandwiches){
        Stack<Integer> shape= new Stack<>();
        Queue<Integer> qu = new LinkedList<>();

        for(int i : sandwiches){
            shape.push(i);
        }
        for(int i : students){
            qu.add(i);
        }

        while(!shape.isEmpty()){ 
            if(qu.peek() == shape.peek()){
                qu.poll();
                shape.pop();
            }
            else{
                qu.add(qu.poll());
            }
        }
        return qu.size();
    }
}
