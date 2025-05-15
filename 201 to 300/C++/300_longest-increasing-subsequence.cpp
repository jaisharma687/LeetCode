#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int t[2501][2501];
//     int dfs(vector<int>& nums, int i, int prev){
//         if(i==nums.size()){
//             return 0;
//         }
//         if(t[i][prev+1]!=-1){
//             return t[i][prev+1];
//         }
//         int not_take = dfs(nums,i+1,prev);
//         int take = (prev==-1 || nums[i]>nums[prev]) ? 1 + dfs(nums,i+1,i) : 0;
//         return t[i][prev+1] = max(take,not_take);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         memset(t,-1,sizeof(t));
//         dfs(nums, 0, -1);
//         for(int i=0;i<3;i++){
//             for(int j=0;j<3;j++){
//                 cout<<t[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return dfs(nums,0,-1);
//     }
// };

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> t(n,1);
            int mx = 1;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        t[i] = max(t[i], t[j]+1);
                        mx = max(mx, t[i]);
                    }
                }
            }
            return mx;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}