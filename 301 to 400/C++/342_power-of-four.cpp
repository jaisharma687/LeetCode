#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPowerOfFour(int n) {
        double p = n;
        if(p<=0) return false;
        else if(p==1) return true;
        else if(p<1){
            while(p<1) p *= 4;
            return (p==1)?true:false;
        }
        else{
            while(p>1) p /= 4;
            return (p==1)?true:false;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}