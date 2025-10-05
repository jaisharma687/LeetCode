#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int dijkstra(vector<vector<int>>& heights){
        int row = heights.size();
        int col = heights[0].size();
        if(row==1 && col==1) return 0;
        priority_queue<P,vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> res(row,vector<int>(col,INT_MAX));
        res[0][0] = 0;
        while(!pq.empty()){
            auto [d, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            for(auto& [dx,dy]: dir){
                int px = dx+x;
                int py = dy+y;
                if(px>=0 && py>=0 && px<row && py<col){
                    int effort = max(d,abs(heights[x][y] - heights[px][py]));
                    if(effort<res[px][py]){
                        res[px][py] = effort;
                        pq.push({effort,{px,py}});
                    }
                }
            }
        }
        return res[row-1][col-1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}