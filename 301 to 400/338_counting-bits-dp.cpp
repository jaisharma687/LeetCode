#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> dp(n+1);
        for(int i=1;i<n+1;i++){
            if(i%2==0){
                dp[i] = dp[i/2];
            }else{
                dp[i] = dp[i-1] + 1;
            }
        }
        return dp;
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}