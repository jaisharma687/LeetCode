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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] res = new int[m][n];
        for(int[] x: res) Arrays.fill(x,-1);
        ListNode temp = head;
        int r_min = 0;
        int c_min = 0;
        int r_max = m-1;
        int c_max = n-1;
        while(temp!=null){
            for(int j=c_min;j<=c_max && temp!=null;j++){
                res[r_min][j] = temp.val;
                temp = temp.next;
            }
            r_min++;
            for(int j=r_min;j<=r_max && temp!=null;j++){
                res[j][c_max] = temp.val;
                temp = temp.next;
            }
            c_max--;
            for(int j=c_max;j>=c_min && temp!=null;j--){
                res[r_max][j] = temp.val;
                temp = temp.next;
            }
            r_max--;
            for(int j=r_max;j>=r_min && temp!=null;j--){
                res[j][c_min] = temp.val;
                temp = temp.next;
            }
            c_min++;
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}