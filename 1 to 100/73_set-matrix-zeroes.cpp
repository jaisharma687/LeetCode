#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows,cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    rows.emplace(i);
                    cols.emplace(j);
                }
            }
        }
        for(auto i: rows){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j] = 0;
            }
        }
        for(auto j: cols){
            for(int i=0;i<matrix.size();i++){
                matrix[i][j] = 0;
            }
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}