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
    void solve(vector<string> solution, vector<int> pos,string solString, vector<bool> visited, int n, int& count){
        if(solution.size()==n){
            if(validate(pos,n)){
                count++;
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
                solve(solution,pos,solString,visited,n,count);
                pos.pop_back();
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        string solString = "";
        for(int i=0;i<n;i++) solString += ".";
        vector<bool> visited(n,false);
        int count = 0;
        solve({},{},solString,visited,n,count);
        return count;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}