#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res;
        int i;
        for(i=0;i+k<=n;i+=k){
            res.push_back(s.substr(i,k));
        }
        string j = s.substr(i);
        if(j!=""){
            while(j.size()!=k) j.push_back(fill);
            res.push_back(j);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}