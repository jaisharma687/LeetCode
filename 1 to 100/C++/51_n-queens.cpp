#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool validate(vector<int> pos,int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = j-i;
                int y = pos[j] - pos[i];
                if(x==abs(y)) return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>& res, vector<string> solution, vector<int> pos,string solString, vector<bool> visited, int n){
        if(solution.size()==n){
            if(validate(pos,n)){
                res.push_back(solution);
            }
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                visited[i] = true;
                string p = solString;
                p[i] = 'Q';
                solution.push_back(p);
                pos.push_back(i);
                solve(res,solution,pos,solString,visited,n);
                pos.pop_back();
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string solString = "";
        for(int i=0;i<n;i++) solString += ".";
        vector<bool> visited(n,false);
        solve(res,{},{},solString,visited,n);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}