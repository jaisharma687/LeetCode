#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = m-1;
        int j = 0;
        int k = 0;
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j]<0){
                k += n - j;
                i--;
            }else j++;
        }
        return k;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}