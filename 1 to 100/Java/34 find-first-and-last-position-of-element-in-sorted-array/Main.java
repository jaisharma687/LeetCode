import java.util.*;

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        res[0] = -1;
        res[1] = -1;
        int left = 0;
        int right = nums.length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                int l = mid;
                int r = mid;
                while(l>=0 && nums[l]==target) l--;
                while(r<nums.length && nums[r]==target) r++;
                res[0] = l+1;
                res[1] = r-1;
                break;
            }
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}