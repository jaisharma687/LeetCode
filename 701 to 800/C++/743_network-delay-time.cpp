#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<P>> adj;
        for(auto& time: times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[0] = -1;
        dist[k] = 0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto& [v,w]: adj[u]){
                if(w+d<dist[v]){
                    dist[v] = w+d;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxTime = *max_element(dist.begin(),dist.end());
        if(maxTime==INT_MAX) return -1;
        else return maxTime;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}