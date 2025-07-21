#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long minLoss = INT_MAX;
        long long sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int u = nums[i]^k;
            if(nums[i]<u){
                count++;
                sum += u;
            }else{ 
                sum += nums[i];
            }
            minLoss = min(minLoss, (long long)abs(u - nums[i]));
        }
        return (count%2==0)?(sum):(sum-minLoss);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}