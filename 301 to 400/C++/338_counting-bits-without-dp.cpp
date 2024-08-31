#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int binary(int n){
        int bin = 0;
        while(n!=0){
            int rem = n%2;
            if(rem == 1){
                bin++;
            }
            n /= 2;
        }
        return bin;
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++){
            dp[i] = binary(i);
        }
        return dp;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}