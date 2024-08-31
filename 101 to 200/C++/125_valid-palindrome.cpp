#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> p;
        for(auto x:s)
            if(isalnum(x)) p.emplace_back(tolower(x));
        vector<char> rev;
        for(int i=p.size()-1;i>=0;i--)
            rev.emplace_back(p[i]);
        return rev == p;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}