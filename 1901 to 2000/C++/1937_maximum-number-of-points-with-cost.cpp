#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n,0);
        for(int col=0;col<n;col++) prev[col] = points[0][col];
        for(int row=1;row<m;row++){
            vector<long long> left(n,0);
            left[0] = prev[0];
            for(int col=1;col<n;col++){
                left[col] = max(prev[col],left[col-1]-1);
            }
            vector<long long> right(n,0);
            right[n-1] = prev[n-1];
            for(int col=n-2;col>=0;col--){
                right[col] = max(prev[col],right[col+1]-1);
            }
            for(int col=0;col<n;col++){
                prev[col] = max(left[col],right[col]) + points[row][col];
            }
        }
        return *max_element(begin(prev),end(prev));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}