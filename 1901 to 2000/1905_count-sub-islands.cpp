#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int row,int col,vector<vector<bool>>& visited){
        int m = grid2.size();
        int n = grid2[0].size();
        bool res = true;
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(grid1[r][c]!=1) res = false;
            vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto d:dir){
                int dr = r + d.first;
                int dc = c + d.second;
                if(dr>=0 && dr<m && dc>=0 && dc<n && grid2[dr][dc]==1 && !visited[dr][dc]){
                    visited[dr][dc] = true;
                    q.push({dr,dc});
                }
            }
        }
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if (grid2[row][col] == 1 && !visited[row][col]) {
                    if (bfs(grid1, grid2, row, col, visited)) {
                        subIslands++;
                    }
                }
            }
        }
        return subIslands;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}