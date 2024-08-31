#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]}); 
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> path(n,0);
        path[start_node] = 1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            pair<double,int> node = pq.top();
            pq.pop();
            double prob = node.first;
            int nd = node.second;
            if (nd == end_node) {
                return prob;
            }
            for(auto p:graph[nd]){
                if(p.second>0 && prob*p.second>path[p.first]){
                    path[p.first] = prob*p.second;
                    pq.push({path[p.first],p.first});
                } 
            }
        }
        return path[end_node];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}