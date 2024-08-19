#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPrime(int k){
        if(k==1) return false;
        if(k==2 || k==3) return true;
        if(k%2 ==0 || k%3 == 0) return false;
        for(int i=5;i*i<=k;i+=2){
            if(k%i==0) return false;
        }
        return true;
    }
    int minSteps(int n) {
        if(isPrime(n)) return n;
        int res = 0;
        int k =2;
        while(n!=1){
            if(isPrime(k)){
                while(n%k==0){
                    n /= k;
                    res += k;
                }
            }
            k++;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}