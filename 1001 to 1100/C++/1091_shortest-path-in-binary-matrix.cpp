#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<pair<int,int>> dir = {
        {1,0}, {0,1}, {-1,0}, {0,-1},
        {1,1}, {1,-1}, {-1,1}, {-1,-1}
    };

    // int bfs(vector<vector<int>>& grid){
    //     int n = grid.size();
    //     if(n==1) return grid[0][0]==0 ? 1 : -1;
    //     if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
    //     queue<P> q;
    //     q.push({1,{0,0}});
    //     grid[0][0] = 1;
    //     while(!q.empty()){
    //         auto [d,pos] = q.front();
    //         q.pop();
    //         int x = pos.first;
    //         int y = pos.second;
    //         for(auto& [dx,dy]: dir){
    //             int px = x+dx;
    //             int py = y+dy;
    //             if(px==n-1 && py==n-1) return d+1;
    //             if(px>=0 && py>=0 && px<n && py<n && grid[px][py]==0){
    //                 grid[px][py] = 1;
    //                 q.push({d+1,{px,py}});
    //             }
    //         }
    //     }
    //     return -1;
    // }

    int bfs(vector<vector<int>>& grid){
        int n = grid.size();
        if(n==1) return grid[0][0]==0 ? 1 : -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int path = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(auto& [dx,dy]: dir){
                    int px = x+dx;
                    int py = y+dy;
                    if(px==n-1 && py==n-1) return path+1;
                    if(px>=0 && py>=0 && px<n && py<n && grid[px][py]==0){
                        grid[px][py] = 1;
                        q.push({px,py});
                    }
                }
            }
            path++;
        }
        return -1;
    }

    int dijkstra(vector<vector<int>>& grid){
        int n = grid.size();
        if(n==1) return grid[0][0]==0 ? 1 : -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        vector<vector<int>> res(n,vector<int>(n,INT_MAX));
        res[0][0] = 0;
        minHeap.push({1,{0,0}});
        while(!minHeap.empty()){
            auto [d,pos] = minHeap.top();
            minHeap.pop();
            int x = pos.first;
            int y = pos.second;
            for(auto& [dx,dy]: dir){
                int px = x+dx;
                int py = y+dy;
                if(px>=0 && py>=0 && px<n && py<n && grid[px][py]==0 && d+1<res[px][py]){
                    res[px][py] = d+1;
                    minHeap.push({d+1,{px,py}});
                }
            }
        }
        if(res[n-1][n-1]==INT_MAX) return -1;
        return res[n-1][n-1];
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
        // return dijkstra(grid);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}