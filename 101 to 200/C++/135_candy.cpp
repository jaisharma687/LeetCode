#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                res[i] = max(res[i], res[i-1]+1);
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                res[i] = max(res[i], res[i+1]+1);
        }
        int ans = 0;
        for(int i: res){
            ans += i;
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}