#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// TC: O(V+E) where V is number of vertices and E is number of edges
// SC: O(V+E) for adjacency list and O(V) for visited and inRecursion arrays

// Kahn's Algorithm can also be used to solve this problem
// But here we are using DFS to detect cycle in directed graph

class Solution {
public:
    // bool bfs_kahn(unordered_map<int,vector<int>>& adjList, vector<int>& inDegree, int n){
    //     queue<int> q;
    //     for(int i=0;i<n;i++){
    //         if(inDegree[i]==0) q.push(i);
    //     }
    //     int count = 0;
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         count++;
    //         for(int& v: adjList[u]){
    //             inDegree[v]--;
    //             if(inDegree[v]==0){
    //                 q.push(v);
    //             }
    //         }
    //     }
    //     return count==n; // If True, ie No CYCLE => Can be completed else can't be completed
    // }

    bool dfs(unordered_map<int,vector<int>>& adjList, vector<bool>& visited, vector<bool>& inRecursion, int u){
        visited[u] = true;
        inRecursion[u] = true;
        for(int& v: adjList[u]){
            if(!visited[v] && dfs(adjList, visited, inRecursion, v)) return true;
            else if(inRecursion[v]) return true;
        }
        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        // vector<int> inDegree(n,0);
        for(auto& pre: prerequisites){
            adjList[pre[1]].push_back(pre[0]);
            // inDegree[pre[0]]++;
        }
        // return bfs_kahn(adjList, inDegree, n);

        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(int u=0;u<n;u++){
            if(!visited[u] && dfs(adjList, visited, inRecursion, u)){
                return false; // False cuz cycle detected => cant do all courses
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