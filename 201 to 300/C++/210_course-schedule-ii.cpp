#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    // vector<int> bfs_kahn(unordered_map<int, vector<int>>& adjList, int n, vector<int>& inDegree){
    //     queue<int> q;
    //     for(int u=0;u<n;u++){
    //         if(inDegree[u]==0) q.push(u);
    //     }
    //     vector<int> res;
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         res.push_back(u);
    //         for(int& v: adjList[u]){
    //             inDegree[v]--;
    //             if(inDegree[v]==0){
    //                 q.push(v);
    //             }
    //         }
    //     }
    //     return (res.size()==n)?res:vector<int>();
    // }

    bool dfs(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, vector<bool>& inRecursion, stack<int>& st, int u){
        visited[u] = true;
        inRecursion[u] = true;
        for(int& v: adjList[u]){
            if(!visited[v] && dfs(adjList, visited, inRecursion, st, v)){
                return true;
            }else if(inRecursion[v]==true) return true;
        }
        st.push(u);
        inRecursion[u] = false;
        return false;
    } 

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList; 
        // vector<int> inDegree(n, 0);
        for(auto& perq: prerequisites){
            adjList[perq[1]].push_back(perq[0]);
            // inDegree[perq[0]]++;
        }
        // return bfs_kahn(adjList, n, inDegree);
        stack<int> st;
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(int u=0;u<n;u++){
            if(!visited[u]){
                if(dfs(adjList, visited, inRecursion, st, u)){
                    return vector<int>();
                }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}