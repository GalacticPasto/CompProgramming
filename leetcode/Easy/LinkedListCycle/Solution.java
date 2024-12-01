package LinkedListCycle;

public class Solution {
    public static void main(String[]args){
        ListNode root = new ListNode(1);
        ListNode r1= new ListNode(2);
        ListNode r2 = new ListNode(4);
        ListNode r3 = new ListNode(4);
        ListNode r4 = new ListNode(7);
        ListNode r5 = new ListNode(4);
        root.next = r1;
        r1.next = r2;
        r2.next = r3;
        r3.next = r4;
        r4.next = r5;
        r5.next = r2;
        System.out.println(hasCycle(root));
    } 
    private static boolean hasCycle(ListNode root){
        ListNode slow = root;
        ListNode fast = root;
        while(fast !=null && fast.next !=null){
            fast = fast.next.next;
            slow = slow.next; 
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}
