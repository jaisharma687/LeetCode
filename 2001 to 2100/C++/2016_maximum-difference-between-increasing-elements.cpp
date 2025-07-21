#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxD = -1;
        int mn = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>mn){
                maxD = max(nums[i]-mn, maxD);
            }
            if(nums[i]<mn) mn = nums[i];
        }
        return maxD;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}