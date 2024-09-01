#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    typedef pair<int,int> P;
    int dijkstra(int n, vector<vector<int>>& edges,int src, int dest){
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int>&edge : edges){
            if(edge[2]!=-1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,src});
        vector<int> res(n,INT_MAX);
        while(!pq.empty()){
            int node = pq.top().second;
            int nodeWt = pq.top().first;
            pq.pop();
            if(nodeWt>res[node]) continue;
            for(auto[neig,wt]:adj[node]){
                if(nodeWt+wt<res[neig]){
                    res[neig] = nodeWt + wt;
                    pq.push({res[neig],neig});
                }
            }
        }
        return res[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int shortest_path = dijkstra(n,edges,source,destination);
        if(shortest_path<target){
            return {};
        }
        if (shortest_path == target) {
            for (auto& edge : edges) {
                if (edge[2] == -1) {
                    edge[2] = 1e9;
                }
            }
            return edges;
        }
        bool matched = false;
        for(auto& edge:edges){
            if(edge[2]==-1){
                edge[2] = 1;
                shortest_path = dijkstra(n,edges,source,destination);
                if(shortest_path<=target){
                    edge[2] += target - shortest_path;
                    matched = true;
                    break;
                }
            }
        }
        if(matched ==false) return {};
        for(auto& edge:edges){
            if(edge[2]==-1){
                edge[2] = 1e9;
            }
        }
        return edges;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}