#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,int> mp;
            int prefixSum = 0;
            int count = 0;
            mp[0] = 1;
            for(int i=0;i<n;i++){
                prefixSum += nums[i];
                int reqd = prefixSum - k;
                count += mp[reqd];
                mp[prefixSum] += 1;
            }
            return count;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();