#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size();
            int i=0;
            int mx = -1;
            for(int j=0;j<n;j++){
                if(nums[j]==1){
                    i++;
                }else i = 0;
                mx = max(mx,i);
            }
            return mx;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();