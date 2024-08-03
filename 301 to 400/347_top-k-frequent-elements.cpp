#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
        vector<pair<int,int>> f(freq.begin(),freq.end());
        sort(f.begin(),f.end(),[](auto &a,auto& b){
            return a.second>b.second;
        });
        vector<int> res;
        for(int i=0;i<k;i++) res.emplace_back(f[i].first);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}