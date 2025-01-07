#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int win = 0;
        vector< long long> prefix(n+1,0);
        for(int i=1;i<=n;i++) prefix[i] += prefix[i-1] + nums[i-1];
        long long total = prefix[n];
        if(total<p) return -1;
        while(win<=n){
            int l = 0;
            while(l+win<=n){
                long long s = prefix[l+win] - prefix[l];
                if(((long long)(total-s))%p==0 && total!=s) return win;
                if(win!=0) l++;
                else break;
            }
            win++;
        }
        return -1;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();