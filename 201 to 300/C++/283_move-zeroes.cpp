#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i] == 0 && nums[j] != 0){
//                     int temp = nums[i];
//                     nums[i] = nums[j];
//                     nums[j] = temp;
//                 }
//             }
//         }
//     }
// };

class Solution {
    public:
        // Two pointers
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            int i = 0;
            for(int j=0;j<n;j++){
                if(nums[j]!=0){
                    swap(nums[i],nums[j]);
                    i++;
                }
            }
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}