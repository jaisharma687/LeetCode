import java.util.*;

class Solution {
    //Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public boolean traverse(ListNode head, TreeNode root){
        if(head==null) return true;
        if(root==null) return false;
        if(head.val == root.val){
            if(traverse(head.next,root.left)) return true;
            if(traverse(head.next,root.right)) return true;
        }
        return false;
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root==null) return false;
        if(traverse(head,root)) return true;
        if(isSubPath(head,root.left)) return true;
        if(isSubPath(head,root.right)) return true;
        return false;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}