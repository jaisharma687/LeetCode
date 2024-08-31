#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int t[101][101];
    int solve(string& s, int l, int r){
        if(l==r) return 1;
        if(l>r) return 0;
        if(t[l][r]!=-1) return t[l][r];
        int i ;
        for(i=l;i<r;i++)
            if(s[i]!=s[i+1]) break;
        if(i==r) return t[l][r]=1;
        int ans = 1 + solve(s,i+1,r);
        int k = INT_MAX;
        for(int j=i+1;j<=r;j++){
            if(s[j]==s[l]){
                k = min(k, solve(s,i+1,j-1)+solve(s,j,r));
            }
        }
        return t[l][r] = min(k,ans);
    }
    int strangePrinter(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.size()-1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}