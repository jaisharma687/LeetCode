#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> n;
        for(int i=0;i<names.size();i++){
            n.push_back({heights[i],names[i]});
        }
        sort(n.begin(),n.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });//lambda function
        vector<string> res;
        for(auto& p : n){
            res.push_back(p.second);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}