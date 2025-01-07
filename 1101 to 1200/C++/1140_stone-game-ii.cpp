#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(vector<int>& piles, int person,int i, int M){
        if(i>=n) return 0;
        if(t[person][i][M]!=-1) return t[person][i][M];
        int stones = 0;
        int res = (person)?-1:INT_MAX;
        for(int x=1;x<=min(2*M,n-i);x++){
            stones+= piles[i+x-1];
            if(person) res = max(res,stones+solve(piles,0,i+x,max(M,x)));
            else res = min(res,solve(piles,1,i+x,max(M,x)));
        }
        return t[person][i][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solve(piles,1,0,1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}