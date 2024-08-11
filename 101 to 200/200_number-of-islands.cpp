#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void bfs(vector<vector<char>> &grid, int r, int c,vector<vector<bool>> &visit){
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto x:dir){
                int dr = row + x.first;
                int dc = col + x.second;
                if(dr>=0 && dr<grid.size() && dc>=0 && dc<grid[0].size() && grid[dr][dc]=='1' && visit[dr][dc]==false){
                    visit[dr][dc] = true;
                    q.push({dr,dc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visit(rows,vector<bool>(cols,false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == '1' && visit[r][c]==false){
                    bfs(grid,r,c,visit);
                    islands++;
                }
            }
        }
        return islands;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}