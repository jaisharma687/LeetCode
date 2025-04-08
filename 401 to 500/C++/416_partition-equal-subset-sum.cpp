#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int t[201][20001];
        bool dfs(vector<int>& nums, int totalSum, int currSum, int i){
            if(i==nums.size()){
                if(totalSum-currSum == currSum){
                    return true;
                }
                return false;
            }
            if(t[i][currSum]!=-1){
                return t[i][currSum];
            }
            return t[i][currSum] = dfs(nums, totalSum, currSum, i+1) || dfs(nums, totalSum, currSum + nums[i], i+1);
        }
        bool canPartition(vector<int>& nums) {
            int totalSum = 0;
            for(int x: nums){
                totalSum += x;
            }
            if(totalSum%2==1){
                return false;
            }
            memset(t,-1,sizeof(t));
            return dfs(nums,totalSum,0,0);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}