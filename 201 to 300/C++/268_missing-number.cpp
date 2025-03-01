#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         if(nums.size() && nums[0]!=0){
//             return 0;
//         }
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i+1] - nums[i] == 2){
//                 return nums[i] + 1;
//             }
//         }
//         return nums.size();
//     }
// };

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int xorN = 0;
            int n = nums.size();
            for(int i=0;i<n;i++){
                xorN ^= nums[i];
                xorN ^= i;
            }
            xorN ^= n;
            return xorN;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}