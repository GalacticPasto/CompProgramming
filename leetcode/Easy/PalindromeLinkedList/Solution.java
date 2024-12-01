package PalindromeLinkedList;

public class Solution {
    public static void main(String[]args){

        ListNode d = new ListNode(2);
        ListNode c = new ListNode(3,d);
        ListNode b = new ListNode(3,c);
        ListNode a = new ListNode(2,b);
        ListNode head = new ListNode(1, a);

        printList(head);
        System.out.println(isPalindrome(head));
    }    
    private static boolean isPalindrome(ListNode head){
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        while(fastPtr != null && fastPtr.next !=null){
            fastPtr = fastPtr.next.next;
            slowPtr = slowPtr.next;
        }
        ListNode node = null;
        while(slowPtr !=null){
           ListNode next = slowPtr.next;
           slowPtr.next = node;
           node = slowPtr;
           slowPtr = next; 
        }
        while(node !=null){
            if(head.val != node.val){
                return false;
            }
            head = head.next;
            node = node.next;
        }
        return true;
    }
    private static void printList(ListNode head){
        while(head != null){
            System.out.print(head.val + " -->");
            head = head.next;
        }
        System.out.println();
    }
}
