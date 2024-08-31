#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        double p = n;
        if(p<=0){
            return false;
        }else if(p==1){
            return true;
        }else if(p<1){
            while(p<1){
                p *= 2;
            }
            if(p==1){
                return true;
            }else return false;
        }else{
            while(p>1){
                p /= 2;
            }
            if(p==1){
                return true;
            }else return false;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}