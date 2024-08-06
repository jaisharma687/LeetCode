#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(auto x: word) freq[x]++;
        int s = freq.size();
        int res = 0;
        vector<pair<int,char>> f;
        for(auto x: freq) f.push_back({x.second,x.first});
        sort(f.begin(),f.end(),greater<pair<int,char>>());
        int factor = 0;
        for(int i=0;i<s;i++){
            if(i%8==0) factor++;
            res += f[i].first * factor;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}