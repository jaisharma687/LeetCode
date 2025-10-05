#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
        if(grid[x][y]=='0') return;
        grid[x][y] = '0';
        for(auto& d: dir){
            int dx = x + d.first;
            int dy = y + d.second;
            if(dx>=0 && dy>=0 && dx<m && dy<n && grid[dx][dy]=='1'){
                dfs(grid, dx, dy, m, n);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, int x, int y, int m, int n){
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = '0';
        while(!q.empty()){
            auto pos = q.front();
            q.pop();
            int rx = pos.first;
            int ry = pos.second;
            for(auto& d: dir){
                int dx = rx + d.first;
                int dy = ry + d.second;
                if(dx>=0 && dy>=0 && dx<m && dy<n && grid[dx][dy]=='1'){
                    grid[dx][dy] = '0';
                    q.push({dx,dy});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]=='1'){
                    bfs(grid, x, y, m, n);
                    // dfs(grid, x, y, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}