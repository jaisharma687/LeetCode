#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        int k = original.size();
        if(k!=m*n) return {};
        int i=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                grid[r][c] = original[i++];
            }
        }
        return grid;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}