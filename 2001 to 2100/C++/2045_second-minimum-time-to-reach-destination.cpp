#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& x : edges) {
            adj[x[0]].emplace_back(x[1]);
            adj[x[1]].emplace_back(x[0]);
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<int> secondDist(n + 1, INT_MAX);
        queue<pair<int, int>> q; // pair(node, current_time)
        q.push({1, 0});
        dist[1] = 0;
        while (!q.empty()) {
            auto [node,cur_time] = q.front();
            q.pop();
            int wait_time = (cur_time/change)%2==1 ? change - (cur_time%change):0;
            int next_time = wait_time + cur_time + time;
            for(auto nei : adj[node]){
                if(dist[nei]>next_time){
                    secondDist[nei] = dist[nei];
                    dist[nei] = next_time;
                    q.push({nei,next_time});
                }else if(dist[nei]<next_time && next_time < secondDist[nei]){
                    secondDist[nei] = next_time;
                    q.push({nei,next_time});
                }
            }
        }
        return secondDist[n];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}