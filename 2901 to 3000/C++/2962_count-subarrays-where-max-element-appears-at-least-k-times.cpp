#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long cnt = 0;
//         int maxElement = *max_element(nums.begin(),nums.end());
//         int i=0,j=0;
//         int mxCnt = 0;
//         while(j<n){
//             if(nums[j]==maxElement){
//                 mxCnt++;
//             }
//             while(mxCnt>=k){
//                 cnt += n - j;
//                 if(nums[i]==maxElement){
//                     mxCnt--;
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return cnt;
//     }
// };

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            long long cnt = 0;
            int maxElement = *max_element(nums.begin(),nums.end());
            vector<int> idxs;
            for(int i=0;i<n;i++){
                if(nums[i]==maxElement){
                    idxs.push_back(i);
                }
                if(idxs.size()>=k){
                    int last_idx = idxs[idxs.size()-k];
                    cnt += last_idx + 1;
                }
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}