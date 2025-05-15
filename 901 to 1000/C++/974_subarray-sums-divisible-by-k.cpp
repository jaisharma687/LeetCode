#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            int n = nums.size();
            int s = 0;
            int res = 0;
            unordered_map<int,int> mpp;
            mpp[0]=1;
            for(int i=0;i<n;i++){
                s += nums[i];
                int r = s % k;
                while(r<0) r+=k;
                res += mpp[r];
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