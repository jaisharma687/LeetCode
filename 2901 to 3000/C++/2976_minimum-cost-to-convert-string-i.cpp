#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26,vector<long long>(26,LLONG_MAX));
        for(int i=0;i<26;i++) adj[i][i] = 0;
        for(int i=0;i<original.size();i++){
            int x = original[i]-'a';
            int y = changed[i]-'a';
            adj[x][y] = min(adj[x][y], (long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if (adj[i][k] < LLONG_MAX && adj[k][j] < LLONG_MAX) 
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        long long c = 0;
        for(int i=0;i<source.size();i++){
            int src = source[i]-'a';
            int tar = target[i]-'a';
            if(adj[src][tar]==LLONG_MAX) return -1;
            c += adj[src][tar];
        }
        return c;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}