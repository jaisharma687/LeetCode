#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void recursion(string s, vector<string>& res, int n, int m){
        if(n==0 && m==0){
            res.push_back(s);
            return;
        }
        if(n>0){
            recursion(s+"(",res,n-1,m);
        }
        if(m>n){
            recursion(s+")",res,n,m-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion("",res,n,n);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}