#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        // Solution 1: Using Map
        // TC: O((n+m)log(n+m)) SC: O(n+m)
        // vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        //     map<int,int> mp;
        //     for(auto x: nums1){
        //         mp[x[0]] = x[1];
        //     }
        //     for(auto x: nums2){
        //         if(mp.find(x[0])==mp.end()){
        //             mp[x[0]] = x[1];
        //         }else{
        //             mp[x[0]] += x[1];
        //         }
        //     }
        //     vector<vector<int>> res;
        //     for(auto x: mp){
        //         res.push_back({x.first,x.second});
        //     }
        //     return res;
        // }
    
        // Solution 2: Two Pointer
        // TC: O() SC: O()
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n = nums1.size();
            int m = nums2.size();
            vector<vector<int>> res;
            int i=0,j=0;
            while(i<n && j<m){
                int id1 = nums1[i][0];
                int id2 = nums2[j][0];
                int val1 = nums1[i][1];
                int val2 = nums2[j][1];
                if(id1==id2){
                    res.push_back({id1, val1+val2});
                    i++;
                    j++;
                }else if(id1<id2){
                    res.push_back({id1, val1});
                    i++;
                }else{
                    res.push_back({id2, val2});
                    j++;
                }
            }
            while(i<n){
                int id1 = nums1[i][0];
                int val1 = nums1[i][1];
                res.push_back({id1, val1});
                i++;
            }
            while(j<m){
                int id2 = nums2[j][0];
                int val2 = nums2[j][1];
                res.push_back({id2, val2});
                j++;
            }
            return res;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();