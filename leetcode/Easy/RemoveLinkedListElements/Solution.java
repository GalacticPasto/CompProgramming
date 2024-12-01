package RemoveLinkedListElements;

public class Solution {
    public static void main(String []args){

        ListNode third= new ListNode(7);
        ListNode second= new ListNode(7,third);
        ListNode first= new ListNode(7,second);
        ListNode head = new ListNode(7,first);
        printListNode(head);
        printListNode(remvoeElementsRecursion(head, 7));
        removeElements(head, 0);
    }
    private static ListNode removeElements(ListNode head , int val){
        if(head == null){
            return null;
        }
        ListNode dummy = head;
        while(dummy !=null){
            if(dummy.val == val && dummy.next.val == val){
                dummy = remvoeElementsRecursion(dummy.next, val);
            }
            if(dummy.next.val == val){
               ListNode prev = dummy;
               dummy = dummy.next;
               prev.next = dummy.next; 
            }
            dummy = dummy.next;
        }
        return head;
    }
    private static ListNode remvoeElementsRecursion(ListNode head,int val){
        if(head== null){
            return null;
        }
        ListNode next = remvoeElementsRecursion(head.next, val);
        if(head.val == val){
            return next;
        }
        head.next = next;
        return head;
    }
    private static void printListNode(ListNode head){
        ListNode dummy = head;
        while(dummy != null){
            System.out.print( dummy.val + "-->");
            dummy = dummy.next;
        }    
        System.out.println();
    }
}
