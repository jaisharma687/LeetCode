#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        bool neg = x < 0 ? true: false;
        x = abs(x);
        long rev = 0;
        while(x>0){
            rev = rev *10 + x % 10;
            if(rev > INT_MAX) return 0;
            x /= 10;
        }
        return neg ? -rev:rev;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}