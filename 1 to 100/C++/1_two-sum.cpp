#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int l = nums.size();
//         for(int i=0;i<l-1;i++){
//             int temp = nums[i];
//             for(int j = i+1;j<l;j++){
//                 if(temp + nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> mp;
            mp[nums[0]] = 0;
            int n = nums.size();
            for(int i=1;i<n;i++){
                int rem = target - nums[i];
                if(mp.find(rem)!=mp.end()){
                    return {mp[rem],i};
                }
                mp[nums[i]] = i;
            }
            return {-1,-1};
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}