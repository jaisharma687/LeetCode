import java.util.*;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int x:nums1) pq.add(x);
        for(int x:nums2) pq.add(x);
        int s = nums1.length + nums2.length;
        double a = 0;
        while(pq.size()>s/2){
            a = pq.poll();
        }
        if(s%2==0){
            double b = pq.poll();
            double res = (a+b)/2;
            return res;
        }
        return a;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}