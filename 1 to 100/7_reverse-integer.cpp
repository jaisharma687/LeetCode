#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int reverse(int x) {
        long y =0;
        while(x != 0){
            int r = x%10;
            
            y = y*10+r;
            x = x/10;
        }
        if(y< -pow(2,31) || y > pow(2,31)-1)
            return 0;
        return y;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}