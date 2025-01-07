import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    res[0] = i;
                    res[1] = j;
                    break;
                }
            }
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2,7,11,15};
        int target = 13;
        int[] result = solution.twoSum(nums, target);
        for(int i=0;i<result.length;i++){
            System.out.println(result[i]);
        }
    }
}