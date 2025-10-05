#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// DFS
// TC: O(V + E)
// SC: O(V)

// BFS
// TC: O(V + E)
// SC: O(V)

// DSU
// TC: O(E * α(V))
// SC: O(V)

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u){
        visited[u] = true;
        for(int& v: adj[u]){
            if(!visited[v]){
                dfs(adj, visited, v);
            }
        }
    }
    void bfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int& v: adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int find(int i, vector<int>& parent){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionF(int x, int y, vector<int>& parent, vector<int>& rank){
        int xParent = find(x, parent);
        int yParent = find(y, parent);
        if(xParent == yParent) return;
        if(rank[xParent]>rank[yParent]) parent[yParent] = xParent;
        else if(rank[xParent]<rank[yParent]) parent[xParent] = yParent;
        else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        // unordered_map<int, vector<int>> adj;
        // for(auto& connection: connections){
        //     adj[connection[0]].push_back(connection[1]);
        //     adj[connection[1]].push_back(connection[0]);
        // }
        // int count = 0;
        // vector<bool> visited(n, false);
        // for(int u=0;u<n;u++){
        //     if(!visited[u]){
        //         count++;
        //         bfs(adj, visited, u);
        //     }
        // }
        // return count-1;

        vector<int> parent(n);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int component = n;

        for(auto& conn: connections){
            int u = conn[0];
            int v = conn[1];
            int uParent = find(u, parent);
            int vParent = find(v, parent);
            if(uParent!=vParent){
                unionF(u, v, parent, rank);
                component--;
            }
        }

        return component - 1; // No of cables used to join k component is k-1
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}