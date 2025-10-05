#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y){
        int xParent = find(x);
        int yParent = find(y);
        if(rank[xParent]>rank[yParent]){
            parent[yParent] = xParent;
        }else if(rank[xParent]<rank[yParent]){
            parent[xParent] = yParent;
        }else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(),parent.end(),0);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            unite(u,v);
        }
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[find(i)]++;
        }
        long long res = 0;
        long long sum = 0;
        for(auto& x: mpp){
            res += x.second * (n - sum - x.second);
            sum += x.second;
        }
        return res;
    }


    // void dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int u, long long& ans){
    //     if(visited[u]) return;
    //     visited[u] = true;
    //     ans++;
    //     for(auto& v: adj[u]){
    //         if(!visited[v]){
    //             dfs(adj, visited, v, ans);
    //         }
    //     }
    // }

    // void bfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int st, long long& ans){
    //     queue<int> q;
    //     q.push(st);
    //     visited[st] = true;
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         ans++;
    //         for(int v: adj[u]){
    //             if(!visited[v]){
    //                 q.push(v);
    //                 visited[v] = true;
    //             }
    //         }
    //     }
    // }

    // long long countPairs(int n, vector<vector<int>>& edges) {
    //     unordered_map<int,vector<int>> adj;
    //     for(auto& edge: edges){
    //         adj[edge[0]].push_back(edge[1]);
    //         adj[edge[1]].push_back(edge[0]);
    //     }
    //     vector<bool> visited(n, false);
    //     long long sum = 0;
    //     long long res = 0;
    //     for(int u=0;u<n;u++){
    //         if(!visited[u]){
    //             long long ans = 0;
    //             // dfs(adj, visited, u, ans);
    //             bfs(adj, visited, u, ans);
    //             res += ans * (n - sum - ans);
    //             sum += ans;
    //         }
    //     }
    //     return res;
    // }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}