#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    unordered_map<int,unordered_map<int,int>> memo;
    int solve(vector<int>& nums, int target, int i, int currSum){
        if(i==nums.size()){
            if(target==currSum) return 1;
            else return 0;
        }
        if(memo[i].contains(currSum)){
            return memo[i][currSum];
        }
        int pos = solve(nums,target,i+1,currSum + nums[i]);
        int neg = solve(nums,target,i+1,currSum - nums[i]);
        return memo[i][currSum] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();