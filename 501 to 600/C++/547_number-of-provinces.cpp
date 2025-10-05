#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// TC : O(n^2), SC : O(n)

// If adjList is used, then TC : O(n + e), SC : O(n + e)

class Solution {
public:
    // void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int u, int n){
    //     visited[u] = true;
    //     for(int j=0;j<n;j++){
    //         if(isConnected[u][j] && !visited[j]){
    //             dfs(isConnected, visited, j, n);
    //         }
    //     }
    // }

    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node, int n){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(!visited[j] && isConnected[i][j]){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for(int u = 0;u<n;u++){
            if(!visited[u]){
                // dfs(isConnected, visited, u, n);
                bfs(isConnected, visited, u, n);
                provinces++;
            }
        }
        return provinces;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}