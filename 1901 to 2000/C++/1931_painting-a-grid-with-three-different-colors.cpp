#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    const int mod = 1e9+7;
    vector<string> colStates;
    vector<vector<int>> t;
    // TC: O(3*2^m-1) ~ O(2^m)
    void createColStates(string curr, int m, char prev){
        if(m==curr.size()){
            colStates.push_back(curr);
            return;
        }
        for(char ch: {'R','G','B'}){
            if(prev==ch) continue;
            createColStates(curr+ch, m, ch);
        }
    }
    // TC: O(S*n*S*m) ~ O(n*m*S^2)
    // S is size of the colStates
    // S = 3*2^m-1 ~ 2^m 
    // Total TC: O(n*m*2^2m + 2^m)
    // Total SC: O(S + n*S) ~ O(2^m + n*2^m)
    int solve(int prevState, int remStates, int m){
        if(remStates==0){
            return 1;
        }
        if(t[remStates][prevState]!=-1) return t[remStates][prevState];
        int ways = 0;
        for(int i=0;i<colStates.size();i++){
            if(i==prevState) continue;
            bool valid = true;
            for(int j=0;j<m;j++){
                if(colStates[prevState][j]==colStates[i][j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(i, remStates-1, m))%mod;
            }
        }
        return t[remStates][prevState] = ways;
    }
    int colorTheGrid(int m, int n) {
        createColStates("", m, ' ');
        cout<<colStates.size()<<endl;
        t = vector<vector<int>>(n+1,vector<int>(colStates.size(),-1));
        for(string x: colStates) cout<<x<<endl;
        int ways=0;
        for(int i=0;i<colStates.size();i++){
            ways = (ways + solve(i, n-1, m))%mod;
        }
        return ways;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}