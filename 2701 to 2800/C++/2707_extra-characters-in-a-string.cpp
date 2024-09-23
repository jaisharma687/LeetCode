#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Using Bottom Up DP

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        unordered_set<string> st(begin(dictionary),end(dictionary));
        // dp[i] is the min chracters in string s from index i to index n-1
        for(int i=n-1;i>=0;i--){
            dp[i] = 1 + dp[i+1];
            for(int j=i;j<n;j++){
                string sub = s.substr(i,j-i+1);
                if(st.contains(sub)) dp[i] = min(dp[i],dp[j+1]);
            }
        }
        return dp[0];
    }
};

// Using Recusion and Memoization

// class Solution {
// public:
//     // int t[51];
//     unordered_map<int,int> mp;
//     int solve(int i, string s,unordered_set<string>& st,int n){
//         if(i>=n) return 0;

//         // if(t[i]!=-1){
//         //     return t[i];
//         // }
        
//         if(mp.contains(i)) return mp[i];

//         int result = 1 + solve(i+1,s,st,n);

//         for(int j=i;j<n;j++){
//             string sub = s.substr(i,j-i+1);
//             if(st.contains(sub)){
//                 result = min(result ,solve(j+1,s,st,n));
//             }
//         }
        
//         return mp[i] = result;
//     }
//     int minExtraChar(string s, vector<string>& dictionary) {
//        int n = s.size();
//     //    memset(t,-1,sizeof(t));
//        unordered_set<string> st(begin(dictionary),end(dictionary));
//        return solve(0,s,st,n); 
//     }
// };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();