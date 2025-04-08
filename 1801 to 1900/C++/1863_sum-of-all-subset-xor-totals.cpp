#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int dfs(vector<int>& nums, int i, int total){
//         if(i==nums.size()){
//             return total;
//         }
//         return dfs(nums,i+1,total^nums[i])+ dfs(nums,i+1,total);
//     }
//     int subsetXORSum(vector<int>& nums) {
//         return dfs(nums,0,0);
//     }
// };

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int res = 0;
            for(int x: nums){
                res = res | x;
            }
            return res*(pow(2,nums.size()-1));
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();