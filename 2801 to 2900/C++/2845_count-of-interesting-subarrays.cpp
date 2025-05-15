#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
            int n = nums.size();
            long long res = 0;
            for(int i=0;i<n;i++){
                if(nums[i]%mod==k) nums[i]=1;
                else nums[i]=0;
            }
            long long cnt = 0;
            unordered_map<int,long long> mpp;
            mpp[0]=1;
            for(int i=0;i<n;i++){
                cnt += nums[i];
                int r = cnt%mod;
                int need = (r-k+mod)%mod;
                res+=mpp[need];
                mpp[r]++;
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}