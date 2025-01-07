#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


// DFS solution
class Solution {
public:
    void dfs(vector<vector<int>>& stones,int n,vector<bool>& visited,int index){
        visited[index] = true;
        for(int i=0;i<n;i++){
            if(!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])){
                dfs(stones,n,visited,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,false);
        int grpCount = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,n,visited,i);
                grpCount++;
            }
        }
        return n-grpCount;
    }
};

/*
DSU

class Solution {
public:
    int find(vector<int>&parent, int i){
        if(i==parent[i])
            return i;
        return parent[i]=find(parent,parent[i]);
    }
    void Union(vector<int>&parent, vector<int>&rank,int x,int y){
        int xParent = find(parent,x);
        int yParent = find(parent,y);
        if(xParent == yParent) return;
        if(rank[xParent]<rank[yParent]){
            parent[xParent] = yParent;
        }
        else if(rank[xParent]>rank[yParent]){
            parent[yParent] = xParent;
        }
        else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i] = i;
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(parent,rank,i,j);
                }
            }
        }
        int grpCount = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) grpCount++;
        }
        return n-grpCount;
    }
};
*/


/* Not optimized
class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
            grid[row][col] = 0;
            for (int c = 0; c < n; c++) {
                if (grid[row][c]) {
                    dfs(grid, row, c, m, n);
                }
            }
            for (int r = 0; r < m; r++) {
                if (grid[r][col]) {
                    dfs(grid, r, col, m, n);
                }
            }
        }
        
        int removeStones(vector<vector<int>>& stones) {
            if (stones.empty()) return 0;
            int m = 0, n = 0;
            for (const auto& stone : stones) {
                m = max(m, stone[0] + 1);
                n = max(n, stone[1] + 1);
            }
            vector<vector<int>> grid(m, vector<int>(n, 0));
            for (const auto& stone : stones) {
                grid[stone[0]][stone[1]] = 1;
            }
            int groupCount = 0;
            for (int row = 0; row < m; row++) {
                for (int col = 0; col < n; col++) {
                    if (grid[row][col]) {
                        dfs(grid, row, col, m, n);
                        groupCount++;
                    }
                }
            }
            return stones.size() - groupCount;
        }
};
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}