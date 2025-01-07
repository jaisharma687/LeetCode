#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto x:s) m[x]++;
        int len = 0;
        bool odd = false;
        for(auto x : m){
            int val = x.second;
            if(val % 2 == 0) len += val;
            else len += val -1, odd = true;
        }
        return odd ? len + 1 : len;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}