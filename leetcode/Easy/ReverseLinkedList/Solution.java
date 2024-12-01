package ReverseLinkedList;

public class Solution {
    public static void main(String [] args){
        ListNode fifth= new ListNode(5);
        ListNode fourth = new ListNode(4,fifth);
        ListNode third = new ListNode(3, fourth);
        ListNode second = new ListNode(2, third);
        ListNode first = new ListNode(1, second);
        printListNode(first);
        printListNode(reverseList(first)); 
    }
    public static ListNode reverseList(ListNode head) {
        ListNode dummy = head;
        ListNode prev = null;
        ListNode next = null;
        if(head != null && head.next == null){
            return head;
        }
        while(dummy!= null){
            next = dummy.next;
            dummy.next = prev;
            prev = dummy;
            dummy = next;
        }
        return prev;
    }
    public static void printListNode(ListNode head){
        ListNode dummy = head;
        while(dummy!=null){
            System.out.print(dummy.val + " ");
            dummy = dummy.next;
        }
        System.out.println();
    }
}
