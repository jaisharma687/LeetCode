import java.util.*;

class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    
    int gcd(int a, int b){
        if(b==0) return a; 
        else return gcd(b,a%b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode a = head.next;
        ListNode b = head;
        while(a!=null){
            int gcd = (a.val > b.val) ? gcd(a.val,b.val) : gcd(b.val,a.val);
            ListNode mid = new ListNode(gcd,a);
            b.next = mid;
            b = a;
            a = a.next;
        }
        return head;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}