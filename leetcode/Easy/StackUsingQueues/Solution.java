package StackUsingQueues;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    static class MyStack {
        Queue<Integer> qStack;
        int[] array;
        public MyStack() {
            qStack = new LinkedList<>();
        }

        public void push(int x) {
            qStack.add(x);
            for(int i = 1 ; i < qStack.size() ;i++){
                qStack.add(qStack.remove());
            }
        }

        public int pop() {
            return qStack.remove();
        }

        public int top() {

            return qStack.peek();
        }

        public boolean empty() {

            return qStack.isEmpty();
        }
    }
}
