#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int cnt = 0;
            for(int i=0;i+3<=n;i++){
                if(nums[i]==0){
                    nums[i] ^= 1;
                    nums[i+1] ^= 1;
                    nums[i+2] ^= 1;
                    cnt++;
                }
            }
            if(nums[n-1]==0 || nums[n-2]==0) return -1;
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();