#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> s;
        for(auto x:strs){
            string z = x;
            sort(x.begin(),x.end());
            s[x].push_back(z);
        }
        vector<vector<string>> res;
        for(auto x:s){
            vector<string> temp;
            for(auto y:x.second){
                temp.push_back(y);
            }
            res.push_back(temp);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}