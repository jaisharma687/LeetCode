#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n: nums){
            m[n]++;
        }
        vector<pair<int,int>> p(m.begin(),m.end());
        sort(p.begin(),p.end(),[](auto& a, auto& b){
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });
        vector<int> res;
        for(auto &o : p){
            int i=0;
            while(i<o.second){
                res.push_back(o.first);
                i++;
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