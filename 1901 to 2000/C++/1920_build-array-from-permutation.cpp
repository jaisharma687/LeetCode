#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     vector<int> buildArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n);
//         for(int i=0;i<n;i++){
//             res[i] = nums[nums[i]];
//         }
//         return res;
//     }
// };

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            for(int i=0;i<n;i++){
                nums[i] += 1001 * (nums[nums[i]]%1001);
            }
            for(int i=0;i<n;i++){
                nums[i] /= 1001;
            }
            return nums;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}