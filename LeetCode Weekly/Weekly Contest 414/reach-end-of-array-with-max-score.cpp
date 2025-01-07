#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Recursion

class Solution {
public:
    long long helper(std::vector<int>& nums, int idx, int prev_idx) {
        if (idx == nums.size()) {
            return (idx - 1 - prev_idx) * nums[prev_idx];
        }
        long long result;
        if (nums[prev_idx] < nums[idx]) {
            return max(helper(nums, idx + 1, prev_idx), (idx - prev_idx) * nums[prev_idx] + helper(nums, idx + 1, idx));
        } else {
            return helper(nums, idx + 1, prev_idx);
        }
    }
    long long findMaximumScore(vector<int>& nums) {
        return helper(nums, 1, 0);
    }
};

// Greedy

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        long long prev = 0;
        for(int j=1;j<nums.size();j++){
            if(nums[prev]<=nums[j]){ 
                res += (j-prev)*nums[prev];
                prev = j;    
            }
        }
        res += (nums.size()-1-prev)*nums[prev];
        return res;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}