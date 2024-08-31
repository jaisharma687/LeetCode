#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = nums[0];
        for(int i=1;i<nums.size();i++){
            out ^= nums[i];
        }
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}