package RemoveDuplicatsFromSortedList;

public class Solution {
   public static void main(String []args){

    ListNode fou= new ListNode(0, null);
    ListNode thi= new ListNode(0, fou);
    ListNode sec= new ListNode(0, thi);
    ListNode first= new ListNode(0, sec);
    ListNode head = new ListNode(0, first);
    printList(head);
    printList(delelteDuplicates(head));
   } 
   private static ListNode delelteDuplicates(ListNode head){
        ListNode dummy = head;
        while (dummy != null && dummy.next != null) {
            if(dummy.val == dummy.next.val){
                dummy.next = dummy.next.next;
            }
            else{
                dummy = dummy.next;
            }
        }  
    return head;
   }
   private static void printList(ListNode head){
        ListNode dummy = head;
        while(dummy != null){
            System.out.print(dummy.val + " ");
            dummy = dummy.next;
        }
    System.out.println();
   }
}

