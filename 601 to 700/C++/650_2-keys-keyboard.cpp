#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


// observational approach
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

// recursion and memorization
class Solution {
public:
    int t[1001][1001];
    int solve(int n, int cur, int clip){
        if(cur == n) return 0 ;
        if(cur>n) return 1100;
        if(t[cur][clip]!=-1) return t[cur][clip];
        int copypaste = 1 + 1 + solve(n,cur+cur,cur);
        int paste = 1 + solve(n,cur+clip,clip);
        return t[cur][clip]= min(paste,copypaste);
        
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(t,-1,sizeof(t));
        return  1 + solve(n,1,1);
    }
};


// dp solution
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<int> dp(n+1);
        dp[0]=dp[1]=0;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            int fac = i/2;
            while(fac >= 1){
                if(i%fac==0){
                    dp[i] = dp[fac] + 1 + (i/fac - 1);
                    break;
                }else fac--;
            }
        }
        return dp[n];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}