import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        ListNode temp = head;
        while(temp != null){
            temp = temp.next;
            n++;
        }
        int r = n%k;
        int s = n/k;
        ListNode[] res = new ListNode[k];
        int i = 0;
        temp = head;
        while(r>0){
            ListNode t = new ListNode(0,temp);
            ListNode p = t;
            for(int j=0;j<s+1;j++){
                p = p.next;
            }
            temp = p.next;
            p.next = null;
            res[i] = t.next;
            i++;
            r--;
            k--;
        }
        while(k>0){
            if(temp==null){
                res[i] = null;
            }
            else{
                ListNode t = new ListNode(0,temp);
                ListNode p = t;
                for(int j=0;j<s;j++){
                    p = p.next;
                }
                temp = p.next;
                p.next = null;
                res[i] = t.next;
            }
            i++;
            k--;
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
