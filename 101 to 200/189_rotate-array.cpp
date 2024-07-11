#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> n = nums;
        int l = nums.size();
        k = k % l;
        if(k==0) return;
        for(int i=0;i<nums.size();i++) nums[(i+k)%l] = n[i];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}