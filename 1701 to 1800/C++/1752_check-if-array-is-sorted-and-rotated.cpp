#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            int breaks = 0;
            for(int i=0;i<n;i++){
                if(nums[i]>nums[(i+1)%n]){
                    breaks++;
                }
                if(breaks>1) return false;
            }
            return true;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();