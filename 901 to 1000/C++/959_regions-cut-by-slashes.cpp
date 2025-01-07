#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &g) {
        if (r < 0 || c < 0 || r == g.size() || c == g[0].size() || g[r][c] != 0) return 0;
        g[r][c] = 1;
        return 1 + dfs(r - 1, c, g) + dfs(r + 1, c, g) + dfs(r, c - 1, g) + dfs(r, c + 1, g);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/')
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
                else if (grid[i][j] == '\\')
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                res += dfs(i, j, g) ? 1 : 0;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}