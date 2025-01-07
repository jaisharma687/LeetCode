#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int p = x;
        long rev = 0;
        while(p>0){
            rev = rev *10 + p%10;
            if(rev>INT_MAX) return false;
            p/=10;
        }
        return x==rev;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}