#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool canSteal(vector<int>& nums, int k, int cap){
            int n = nums.size();
            int i = 0;
            int cnt = 0;
            while(i<n){
                if(nums[i]<=cap){
                    cnt++;
                    i+=2;
                }else {
                    i++;
                }
            }
            return cnt >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            int l = *min_element(nums.begin(),nums.end());
            int r = *max_element(nums.begin(),nums.end());
            while(l<r){
                int m = l + (r-l)/2;
                if(canSteal(nums,k,m)){
                    r = m;
                }else{
                    l = m + 1;
                }
            }
            return l;
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