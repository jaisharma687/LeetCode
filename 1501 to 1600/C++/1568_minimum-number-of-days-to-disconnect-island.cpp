#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void bfs(int row, int col,vector<vector<int>>& grid,vector<vector<bool>>& visit){
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto x: dir){
                int dr = r + x.first;
                int dc = c + x.second;
                if(dr>=0 && dc>=0 && dr<grid.size() && dc<grid[0].size() && grid[dr][dc]==1 && visit[dr][dc]==false){
                    visit[dr][dc] = true;
                    q.push({dr,dc});
                }
            }
        }
    }
    int islands(vector<vector<int>>& grid){
        int island = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visit(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visit[i][j]==false && grid[i][j]==1){
                    bfs(i,j,grid,visit);
                    island++;
                    if(island > 1) return island;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        if(islands(grid) == 0 || islands(grid) > 1) return 0;
        else{
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                        grid[i][j] = 0;
                        if(islands(grid)>1 || islands(grid)==0) return 1;
                        grid[i][j] = 1;
                    }
                }
            }
            return 2;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}