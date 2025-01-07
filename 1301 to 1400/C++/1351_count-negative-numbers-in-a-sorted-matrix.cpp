#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int k = 0;
        for(int i=0;i<grid.size();i++){
            int j = grid[i].size() - 1;
            while(j>=0 && grid[i][j]<0) k++,j--;
        }
        return k;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}