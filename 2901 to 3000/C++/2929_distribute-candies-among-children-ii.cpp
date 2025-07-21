#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i=0;i<=min(n, limit);i++){
            if(n-i <= 2* limit){
                ans += min(n-i, limit) - max(0, n-i-limit) + 1;
            }
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}