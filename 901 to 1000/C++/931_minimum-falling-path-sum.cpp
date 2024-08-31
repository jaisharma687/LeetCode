#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0);
        for(int col = 0;col<n;col++) prev[col] = matrix[0][col];
        for(int row = 1;row<m;row++){
            vector<int> curr(n,0);
            for(int col = 0;col<n;col++){
                int minValue = INT_MAX;
                minValue = min(minValue,prev[col]);
                if(col!=0) minValue = min(minValue,prev[col-1]);
                if(col!=n-1) minValue = min(minValue,prev[col+1]);
                curr[col] = minValue + matrix[row][col];
            }
            prev = curr;
        }
        return *min_element(begin(prev),end(prev));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}