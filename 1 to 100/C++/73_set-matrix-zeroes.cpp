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

class Solution {
    public:
    
        // Solution 1: TC: O(2*n*m) SC: O(n+m)
        // void setZeroes(vector<vector<int>>& matrix) {
        //     int n = matrix.size();
        //     int m = matrix[0].size();
        //     unordered_set<int> rows;
        //     unordered_set<int> cols;
        //     for(int i=0;i<n;i++){
        // 	    for(int j=0;j<m;j++){
        // 		    if(matrix[i][j]==0){
        // 			    rows.insert(i);
        // 			    cols.insert(j);
        // 		    }
        // 	    }
        //     }
        //     for(auto it: rows){
        // 	    for(int j=0;j<m;j++){
        // 		    matrix[it][j] = 0;
        // 	    }
        //     }
        //     for(auto it: cols){
        // 	    for(int i=0;i<n;i++){
        // 		    matrix[i][it] = 0;
        // 	    }
        //     }
        // }
    
        // Solution 1: TC: O(2*n*m) SC: O(1)
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            int col = 1;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        matrix[i][0] = 0;
                        if(j!=0){
                            matrix[0][j] = 0;
                        }else{
                            col = 0;
                        }
                    }
                }
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j] = 0;
                    }
                }
            }
            // for the 1st row
            if(matrix[0][0]==0){
                for(int j=0;j<m;j++){
                    matrix[0][j] = 0;
                }
            }
            // for the 1st col
            if(col==0){
                for(int i=0;i<n;i++){
                    matrix[i][0] = 0;
                }
            }
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}