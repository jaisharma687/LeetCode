#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        //Solution 1: O(nlogn)
        // int maximCrossSubArr(vector<int>& nums, int low, int mid, int high){
        //     int leftSum = INT_MIN;
        //     int rightSum = INT_MIN;
        //     int sum = 0;
        //     for(int i=mid;i>=0;i--){
        //         sum = sum+nums[i];
        //         leftSum = max(sum,leftSum);
        //     }
        //     sum = 0;
        //     for(int i=mid+1;i<=high;i++){
        //         sum = sum+nums[i];
        //         rightSum = max(sum,rightSum);
        //     }
        //     return leftSum + rightSum;
        // }
        // int maximSubArr(vector<int>& nums,int low, int high){
        //     if(low==high){
        //         return nums[low];
        //     }
        //     int mid = low + (high-low)/2;
        //     int leftSum = maximSubArr(nums,low,mid);
        //     int rightSum = maximSubArr(nums,mid+1,high);
        //     int crossSum = maximCrossSubArr(nums,low,mid,high);
        //     return max(leftSum,max(rightSum,crossSum));
        // }
        // int maxSubArray(vector<int>& nums) {
        //     return maximSubArr(nums,0,nums.size()-1);
        // }
    
        //Solution 2: O(n)
        int maxSubArray(vector<int>& nums) {
            int maxSum = INT_MIN;
            int sum = 0;
            for(int x: nums){
                sum += x;
                maxSum = max(maxSum, sum);
                if(sum<0){
                    sum=0;
                }
            }
            return maxSum;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();