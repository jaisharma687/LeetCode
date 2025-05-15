#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int countPairs(vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]==nums[j] && (i*j)%k==0) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,vector<int>> idxMap;
            for(int i=0;i<n;i++){
                idxMap[nums[i]].push_back(i);
            }
            unordered_set<int> div;
            for(int i=1;i*i<=k;i++){
                if(k%i==0){
                    div.insert(i);
                    div.insert(k/i);
                }
            }
            int res = 0;
            for(auto& [num, idxs]: idxMap){
                unordered_map<int,int> factorMap;
                for(int idx: idxs){
                    int gcdd = gcd(k,idx);
                    res += factorMap[k/gcdd];
                    for(int d: div){
                        if(idx%d==0){
                            factorMap[d]++;
                        }
                    }
                }
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}