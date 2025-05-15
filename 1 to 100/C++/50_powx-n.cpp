#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/*
    Explaination
    https://www.youtube.com/watch?si=g_nvLVFWh7WXen3R&v=-mNn11iRZ5k&feature=youtu.be
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            x = 1/x;
            n = abs(n);
        }
        double v = myPow(x,n/2);
        if(n%2){
            return x*v*v;
        }else return v*v;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double res = 1;
        if(n<0){
            x = 1/x;
            N = -N;
        }
        while(N>0){
            if(N%2==1) res *= x;
            x *= x;
            N /= 2;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}