#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if(n==0) return 0;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int j=1;j<=n;j++){
            int cur_height = 0;
            int cur_width = 0;
            int k = 1;
            for(int k=1; k<=j; k++){
                cur_width += books[j-k][0];
                if(cur_width > shelfWidth) break;
                cur_height = max(cur_height, books[j-k][1]);
                dp[j] = min(dp[j],dp[j-k]+cur_height);
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