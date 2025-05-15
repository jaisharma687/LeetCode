#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int countDistinctElements(unordered_map<int,int> freqMap){
            int cnt = 0;
            for(auto& [num, freq]: freqMap){
                if(freq>=1){
                    cnt++;
                }
            }
            return cnt;
        }
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            int k = unordered_set<int>(nums.begin(),nums.end()).size();
            int i=0,j=0;
            int res = 0;
            unordered_map<int,int> freqMap;
            while(j<n){
                freqMap[nums[j]]++;
                while(countDistinctElements(freqMap)==k){
                    res += n - j;
                    freqMap[nums[i]]--;
                    i++;
                }
                j++;
            }
            return res;
        }
    };
    
    // class Solution {
    // public:
    //     int countCompleteSubarrays(vector<int>& nums) {
    //         int n = nums.size();
    //         int k = unordered_set<int>(nums.begin(),nums.end()).size();
    //         int i=0,j=0;
    //         int res = 0;
    //         for(int i=0;i<n;i++){
    //             unordered_set<int> seen;
    //             for(int j=i;j<n;j++){
    //                 seen.insert(nums[j]);
    //                 if(seen.size()==k){
    //                     res += n - j;
    //                     break;
    //                 }
    //             }
    //         }
    //         return res;
    //     }
    // };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}