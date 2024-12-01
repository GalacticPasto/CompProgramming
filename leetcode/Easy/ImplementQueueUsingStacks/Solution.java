package ImplementQueueUsingStacks;

import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        MyQueue q = new MyQueue();
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        System.out.println(q.pop());
        q.push(5);
        System.out.println(q.pop());
        System.out.println(q.pop());
        System.out.println(q.pop());
        System.out.println(q.pop());
        System.out.println(q.empty());
    }

    private static class MyQueue {
        Stack<Integer> stack1;
        Stack<Integer> stack2;
        private MyQueue() {
            stack1 = new Stack<>();
            stack2 = new Stack<>();
        }
        public void push(int x) {
            while(!stack2.isEmpty()){
                stack1.push(stack2.pop());
            }
            stack1.push(x);
            while(!stack1.isEmpty()){
                stack2.push(stack1.pop());
            }
        }

        public int pop() {
            return stack2.pop();    
        }

        public int peek() {
            return stack2.peek();
        }

        public boolean empty() {
            return stack2.isEmpty();
        }
    }
}
