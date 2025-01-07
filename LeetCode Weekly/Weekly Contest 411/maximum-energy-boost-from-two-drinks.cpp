#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long max(long long a, long long b){
        return a>b?a:b;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(2,vector<long long>(n,0));
        dp[0][0] = energyDrinkA[0];
        dp[1][0] = energyDrinkB[0];
        dp[0][1] = max(energyDrinkA[1]+dp[0][0],dp[1][0]);
        dp[1][1] = max(energyDrinkB[1]+dp[1][0],dp[0][0]);
        for(int i=2;i<n;i++){
            dp[0][i] = max(dp[0][i-1],dp[1][i-2])+energyDrinkA[i];
            dp[1][i] = max(dp[1][i-1],dp[0][i-2])+energyDrinkB[i];
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}