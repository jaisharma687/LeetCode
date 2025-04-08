#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     bool isDistinct(vector<int> &nums, int i){
//         int n = nums.size();
//         unordered_set<int> st;
//         for(int j=i;j<n;j++){
//             if(st.find(nums[j])==st.end()){
//                 st.insert(nums[j]);
//             }else{
//                 return false;
//             }
//         }
//         return true;
//     }
//     int minimumOperations(vector<int>& nums) {
//         int ops = 0;
//         int i = 0;
//         while(true){
//             if(isDistinct(nums,i)){
//                 break;
//             }else{
//                 ops++;
//                 i+=3;
//             }
//         }
//         return ops;
//     }
// };

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size(),i;
            unordered_set<int> st;
            for(i=n-1;i>=0;i--){
                if(st.find(nums[i])==st.end()){
                    st.insert(nums[i]);
                }else{
                    return i/3 + 1;
                }
            }
            return 0;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}