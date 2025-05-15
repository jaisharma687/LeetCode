#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int n = nums.size();
            long long cnt = 0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                int lower_idx = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]) - nums.begin();
                int upper_idx = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]) - nums.begin();
                cnt += upper_idx - lower_idx;
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}