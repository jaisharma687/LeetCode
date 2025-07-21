#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int bfs(unordered_map<int, vector<int>>& adj, int k, int& src){
        if(k<0) return 0; 
        queue<int> q;
        q.push(src);
        int cnt = 1;
        unordered_set<int> visited;
        visited.insert(src);
        while(!q.empty()){
            int size = q.size();
            if(k<=0) break;
            while(size--){
                auto node = q.front();
                q.pop();
                for(auto& neigh: adj[node]){
                    if(!visited.count(neigh)){
                        q.push(neigh);
                        visited.insert(neigh);
                        cnt++;
                    }
                }
            }
            k--;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;
        for(auto edge: edges1){
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto edge: edges2){
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxBFS = 0;
        for(int u = 0; u<=m ; u++){
            maxBFS = max(maxBFS, bfs(adj2, k-1, u));
        }
        vector<int> res(n+1);
        for(int u=0;u<=n;u++){
            res[u] = bfs(adj1, k, u) + maxBFS;
        }
        return res;
    }
};

// class Solution {
// public:
//     int bfs(unordered_map<int, vector<int>>& mpp, int k, int& src){
//         queue<int> q;
//         q.push(src);
//         int cnt = 1;
//         unordered_set<int> visited;
//         visited.insert(src);
//         while(!q.empty()){
//             int size = q.size();
//             if(k==0) break;
//             while(size--){
//                 auto node = q.front();
//                 q.pop();
//                 for(auto& neigh: mpp[node]){
//                     if(!visited.count(neigh)){
//                         q.push(neigh);
//                         visited.insert(neigh);
//                         cnt++;
//                     }
//                 }
//             }
//             k--;
//         }
//         return cnt;
//     }
//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
//         unordered_map<int, vector<int>> mpp;
//         int n = edges1.size();
//         int m = edges2.size();
//         for(auto edge: edges1){
//             int u = edge[0];
//             int v = edge[1];
//             mpp[u].push_back(v);
//             mpp[v].push_back(u);
//         }
//         for(auto edge: edges2){
//             int u = edge[0]+1001;
//             int v = edge[1]+1001;
//             mpp[u].push_back(v);
//             mpp[v].push_back(u);
//         }
//         vector<int> res;
//         for(int u=0;u<=n;u++){
//             int mx = INT_MIN;
//             for(int v=1001;v<=m+1001;v++){
//                 mpp[u].push_back(v);
//                 mpp[v].push_back(u);
//                 mx = max(mx, bfs(mpp, k, u));
//                 mpp[v].pop_back();
//                 mpp[u].pop_back();
//             }
//             res.push_back(mx);
//         }
//         return res;
//     }
// };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}