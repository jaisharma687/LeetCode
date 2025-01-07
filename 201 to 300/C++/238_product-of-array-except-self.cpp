#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int pre = nums[0];
        prefix[0] = 1;
        for(int i=1;i<n;i++){
            prefix[i] = pre;
            pre *= nums[i];
        }
        vector<int> suffix(n);
        int suf = nums[n-1];
        suffix[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            suffix[i] = suf;
            suf *= nums[i];
        }
        vector<int> res(n);
        for(int i=0;i<n;i++) res[i] = prefix[i] * suffix[i];
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}