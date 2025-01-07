#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int two = 0;
        int three = 0;
        int five = 0;
        for(int i=1;i<n;i++){
            int n1 = dp[two]*2;
            int n2 = dp[three]*3;
            int n3 = dp[five]*5;
            dp[i] = min(n1,min(n2,n3));
            if(dp[i]==n1) two++;
            if(dp[i]==n2) three++;
            if(dp[i]==n3) five++;
        }
        return dp[n-1];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}