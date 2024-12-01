package ConvertBinaryNumberLinkedListToINt;

public class Solution {
    public static void main(String[] args){
        ListNode thi = new ListNode(1);
        ListNode sec = new ListNode(0,thi);
        ListNode head = new ListNode(1, sec);
        System.out.println(getDecimalValue(head));
        System.out.println(getDecimalValueEasy(head));
    } 
    private static int getDecimalValue(ListNode head){
        ListNode dummy = head;
        StringBuilder sb = new StringBuilder();
        while(dummy != null){
            sb.append(dummy.val);
            dummy = dummy.next;
        }
        int i = 0; 
        int pow = sb.length()-1;
        int ans = 0 ;
        dummy = head;
        while(i < sb.length()){
            ans += dummy.val*Math.pow(2,pow);
            i++;
            pow--;
            dummy = dummy.next;
        }
        return ans;
    }
    private static int getDecimalValueEasy(ListNode head){
        int ans = 0 ; 
        while(head != null){
            ans = (ans << 1)+ head.val;
            head = head.next;
        }
        return ans;
    }
}
