#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int,int> mp;
            int cnt = 0;
            for(auto x: dominoes){
                int mx = max(x[0], x[1]);
                int mn = min(x[0], x[1]);
                int key = mx*10 + mn;
                cnt += mp[key];
                mp[key]++;
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}