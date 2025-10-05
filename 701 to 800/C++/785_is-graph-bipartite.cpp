#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// TC: O(V+E) where V is number of vertices and E is number of edges
// SC: O(V+E) for adjacency list and O(V) for color array

class Solution {
public:
    // bool dfs(vector<vector<int>>& graph, vector<int>& color, int curr, int currColor){
    //     color[curr] = currColor;
    //     for(int& v: graph[curr]){
    //         if(color[v]==color[curr]) return false;
    //         else if(color[v]==-1){
    //             if(dfs(graph, color, v, 1-currColor)==false) return false;
    //         }
    //     }
    //     return true;
    // }

    bool bfs(vector<vector<int>>& graph, vector<int>& color, int curr, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int& v: graph[u]){
                if(color[v]==color[u]) return false;
                else if(color[v]==-1){
                    q.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int u=0;u<n;u++){
            if(color[u]==-1){
                // if(dfs(graph, color, u, 0)==false) return false;
                if(bfs(graph, color, u, 0)==false) return false;
            }
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}