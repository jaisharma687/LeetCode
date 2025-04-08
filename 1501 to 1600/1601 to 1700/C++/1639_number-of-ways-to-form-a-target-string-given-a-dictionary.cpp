#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    // i for traversing words
    // j for traversing target
    int t[1001][1001];
    int mod = 1e9+7;
    int solve(vector<string>& words, string& target, int i,int j,vector<vector<long long>>& freq){
        if(j==target.size()){
            return 1;
        }
        if(i>=words[0].size()){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        int notTaken = solve(words,target,i+1,j,freq)%mod;
        int taken = (freq[target[j]-'a'][i] * solve(words,target,i+1,j+1,freq))%mod;
        return t[i][j] = (notTaken + taken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int m = words.size();
        int n = words[0].size();
        vector<vector<long long>> freq(26,vector<long long>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                freq[words[i][j]-'a'][j]++;
            }
        }
        memset(t,-1,sizeof(t));
        return solve(words,target,0,0,freq);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();