package MergeTwoSortedLists;

public class Solution {
    public static void main(String [] args){
        ListNode fourth = new ListNode(4);
        ListNode third = new ListNode(2, fourth);
        ListNode first = new ListNode(1, third);
        

        ListNode se = new ListNode(3);
        ListNode fi  = new ListNode(1, se);
        printListNode(first);
        printListNode(fi);
        printListNode(mergeTwoListNode(first, fi));
   }
    public static ListNode mergeTwoListNode(ListNode list1, ListNode list2){
        ListNode dummy = new ListNode(0);
        ListNode dummyTail = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                dummyTail.next = list1;
                list1 = list1.next;
            } else {
                dummyTail.next = list2;
                list2 = list2.next;
            }
            dummyTail = dummyTail.next;
        }
        while(list1 !=null){
            dummyTail.next = list1;
            list1 = list1.next;
            dummyTail = dummyTail.next;
        }
        while(list2 !=null){
            dummyTail.next = list2;
            list2 = list2.next;
            dummyTail = dummyTail.next;
        }
        return dummy.next;
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
