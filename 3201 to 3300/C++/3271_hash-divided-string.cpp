#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string res = "";
        for(int i=0;i<=n-k;i+=k){
            string sub = s.substr(i,k);
            int hash = 0;
            for(int j=0;j<k;j++) hash += (int)(sub[j]-'a');
            int h = hash % 26;
            char t = (char)(h+'a');
            res += t;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}