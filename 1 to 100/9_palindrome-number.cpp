#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPalindrome(int x) {
        long y = 0;
        long z = x;
        while(x!=0){
            int r = x %10;
            y = y*10+r;
            x = x/10;
        }
        if(z == y && z>=0){
            return true;
        }else{
            return false;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}