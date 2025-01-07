#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// prefix approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n);
        prefix[0] = prices[0];
        for(int i=1;i<n;i++){
            prefix[i] = min(prefix[i-1],prices[i]);
        }
        int m = 0;
        for(int i=1;i<n;i++){
            m = max(m,prices[i]-prefix[i]);
        }
        return m;
    }
};

// sliding window or two pointer
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int d = 0;
        while(r<prices.size()){
            if(prices[r]<prices[l]) l=r,r++;
            else{
                d = max(d,prices[r]-prices[l]);
                r++;
            }
        }
        return d;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}