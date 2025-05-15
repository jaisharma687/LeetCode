#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     vector<int> res;
//     void dfs(vector<int>& nums, int i, vector<int> temp){
//         if(i==nums.size()){
//             if(temp.size()>res.size()){
//                 res = temp;
//             }
//             return;
//         }
//         dfs(nums,i+1,temp);
//         if(temp.size()==0 || nums[i]%temp.back()==0){
//             temp.push_back(nums[i]);
//             dfs(nums,i+1,temp);
//         }
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         dfs(nums,0,vector<int>());
//         return res;
//     }
// };

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            vector<int> t(n,1);
            vector<int> prev(n,-1);
            int mx = 1;
            int mxIdx = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(nums[i]%nums[j]==0){
                        if(t[i]<t[j]+1){
                            t[i] = t[j]+1;
                            prev[i] = j;
                        }
                        if(t[i]>mx){
                            mx = t[i];
                            mxIdx = i;
                        }
                    }
                }
            }
            vector<int> res;
            int j = mxIdx;
            while(j!=-1){
                res.push_back(nums[j]);
                j = prev[j];
            }
            reverse(res.begin(),res.end());
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}