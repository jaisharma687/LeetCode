#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n,0);
        for(auto x: queries){
            int l = x[0];
            int r = x[1];
            diffArr[l] += 1;
            if(r+1<n) diffArr[r+1] -= 1;
        }
        for(int i=0;i<n;i++){
            if(i>0) diffArr[i] += diffArr[i-1];
            if(nums[i]>diffArr[i]) return false;
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}