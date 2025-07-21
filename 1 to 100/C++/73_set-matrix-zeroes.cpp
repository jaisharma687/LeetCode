#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         unordered_set<int> rows,cols;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j] == 0){
//                     rows.emplace(i);
//                     cols.emplace(j);
//                 }
//             }
//         }
//         for(auto i: rows){
//             for(int j=0;j<matrix[0].size();j++){
//                 matrix[i][j] = 0;
//             }
//         }
//         for(auto j: cols){
//             for(int i=0;i<matrix.size();i++){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// };

// Solution 1: TC: O(2*n*m) SC: O(1)
class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row0 = 1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]==0){
                    matrix[0][col] = 0;
                    if(row==0) row0 = 0;
                    else matrix[row][0] = 0;
                }
            }
        }
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(matrix[row][0]==0 || matrix[0][col]==0){
                    matrix[row][col] = 0;
                }
            }
        }
        if(matrix[0][0]==0){ // flag for col0
            for(int row=0;row<m;row++){
                matrix[row][0] = 0;
            }
        }
        if(row0==0){ //flag for row0
            for(int col=0;col<n;col++){
                matrix[0][col] = 0;
            }
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}