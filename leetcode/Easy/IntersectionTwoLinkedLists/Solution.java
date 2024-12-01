package IntersectionTwoLinkedLists;

import java.util.HashSet;

public class Solution {
    public static void main(String []args){
        ListNode headA = new ListNode(4);
        ListNode node1A = new ListNode(1);
        ListNode node2A = new ListNode(8);
        ListNode node3A = new ListNode(4);
        ListNode node4A = new ListNode(5);

        ListNode headB= new ListNode(5);
        ListNode node2B = new ListNode(6);
        ListNode node3B = new ListNode(1);
        
        headA.next = node1A;
        node1A.next = node2A;
        node2A.next = node3A;
        node3A.next = node4A;

        headB.next = node2B;
        node2B.next = node3B;
        node3B.next = node2A;
        
        printLinkedList(headA);
        printLinkedList(headB);
        getIntersectionNode(headA,headB);
    } 


    public static ListNode getIntersectionNode(ListNode headA , ListNode headB){
        HashSet<ListNode> hs = new HashSet<>();

        ListNode currentA= headA;
        while(currentA != null){
            hs.add(currentA);
            currentA = currentA.next;
        }
        ListNode currentB = headB;
        while(currentB != null){
            if(hs.contains(currentB)){
                System.out.println(currentB.val);
                return currentB;
            }
            currentB = currentB.next;
        }
        return null;
    }
    private static void printLinkedList(ListNode head){
        ListNode dummy = head;
        while(dummy != null){
            System.out.print(dummy.val + "--->");
            dummy = dummy.next;
        }
        System.out.println();
    }
}

