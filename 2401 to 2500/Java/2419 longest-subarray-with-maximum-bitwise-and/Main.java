import java.util.*;

class Solution {
    public int longestSubarray(int[] nums) {
        int mx = 0;
        int c = 0;
        int n = nums.length;
        for(int x:nums){
            if(mx<x){
                mx = x;
                c = 0;
            }
            if(mx==x) c++;
        }
        int res = 0;
        int m = 0;
        if(c==1) return 1;
        if(c==n) return n;
        else{
            for(int x:nums){
                if(x==mx) m++;
                else{
                    res = Math.max(res,m);
                    m=0;
                }
            }
        }
        res = Math.max(res,m);
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}