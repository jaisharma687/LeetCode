#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    const int mod = 1e9+7;
    vector<string> rowStates;
    vector<vector<int>> t;
    void generateRowStates(string curr, char prev){
        if(curr.size()==3){
            rowStates.push_back(curr);
            return;
        }
        for(char x: {'R', 'G', 'Y'}){
            if(prev==x) continue;
            generateRowStates(curr + x, x);
        }
    }
    // TC: O(12*n*12*3 + 3*2^2) ~ O(n)
    // SC: O(n*12 + 12) ~ O(n)
    int solve(int prevIdx, int remRows){
        if(remRows==0) return 1;
        if(t[remRows][prevIdx]!=-1) return t[remRows][prevIdx];
        int ways = 0;
        for(int i=0;i<rowStates.size();i++){
            if(i==prevIdx) continue;
            bool valid = true;
            for(int j=0;j<3;j++){
                if(rowStates[prevIdx][j]==rowStates[i][j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways+solve(i,remRows-1))%mod;
            }
        }
        return t[remRows][prevIdx] = ways;
    }
    int numOfWays(int n) {
        generateRowStates("", ' ');
        t = vector<vector<int>>(n+1, vector<int>(rowStates.size(), -1));
        int ways = 0;
        for(int i=0;i<rowStates.size();i++){
            ways = (ways+solve(i,n-1))%mod;
        }
        return ways;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}