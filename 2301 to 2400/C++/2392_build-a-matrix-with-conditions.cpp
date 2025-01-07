#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int src, unordered_set<int>& visited, unordered_set<int>& path, vector<int>& order) {
        if (path.count(src)) return false;
        if (visited.count(src)) return true;
        
        visited.insert(src);
        path.insert(src);
        
        for (auto neighbour : adj[src]) {
            if (!dfs(adj, neighbour, visited, path, order)) {
                return false;
            }
        }
        
        path.erase(src);
        order.push_back(src);
        return true;
    }
    
    vector<int> topological_sort(int k, vector<vector<int>>& conditions) {
        unordered_map<int, vector<int>> adj;
        for (auto x : conditions) {
            adj[x[0]].push_back(x[1]);
        }
        
        unordered_set<int> visited;
        unordered_set<int> path;
        vector<int> order;
        
        for (int i = 1; i <= k; ++i) {
            if (visited.count(i) == 0) {
                if (!dfs(adj, i, visited, path, order)) {
                    return {};
                }
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_order = topological_sort(k, rowConditions);
        vector<int> col_order = topological_sort(k, colConditions);
        
        if (row_order.empty() || col_order.empty()) return {};
        
        unordered_map<int, int> row_pos, col_pos;
        for (int i = 0; i < k; ++i) {
            row_pos[row_order[i]] = i;
            col_pos[col_order[i]] = i;
        }
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matrix[row_pos[i]][col_pos[i]] = i;
        }
        
        return matrix;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}