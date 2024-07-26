#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for (auto x : edges) {
            int from = x[0];
            int to = x[1];
            int weight = x[2];
            adj[from][to] = weight;
            adj[to][from] = weight;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][k] < INT_MAX / 2 && adj[k][j] < INT_MAX / 2) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold && i != j) res[i]++;
            }
        }
        int minReachableCities = INT_MAX;
        int resultCity = -1;
        for (int i = 0; i < n; i++) {
            if (res[i] <= minReachableCities) {
                minReachableCities = res[i];
                resultCity = i;
            }
        }
        return resultCity;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}