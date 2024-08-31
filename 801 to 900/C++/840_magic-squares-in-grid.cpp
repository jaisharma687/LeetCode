#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row<3 || col<3) return 0;
        int magic = 0;
        for(int r=0;r<=row-3;r++){
            for(int c=0;c<=col-3;c++){
                unordered_map<int,int> m;
                int ds1 = grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
                int ds2 = grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
                int rs1 = grid[r][c]+grid[r][c+1]+grid[r][c+2];
                int rs2 = grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2];
                int rs3 = grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2];
                int cs1 = grid[r][c]+grid[r+1][c]+grid[r+2][c];
                int cs2 = grid[r][c+1]+grid[r+1][c+1]+grid[r+2][c+1];
                int cs3 = grid[r][c+2]+grid[r+1][c+2]+grid[r+2][c+2];
                if(ds1 == ds2 && rs1 == rs2 && rs3 == rs1 && cs1 == cs2 && cs3 == cs1){
                    for(int i=r;i<r+3;i++){
                        for(int j=c;j<c+3;j++){
                            if(grid[i][j]<=9 && grid[i][j]>0) m[grid[i][j]]++;
                        }
                    }
                    if(m.size()==9) magic++;
                }
            }
        }
        return magic;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}