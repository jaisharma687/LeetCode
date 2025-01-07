#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        int n = s.length();
        for(int i=1;i<n;i++){
            string st = t.substr(i,n);
            if(st == s){
                return true;
            }
        }
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}