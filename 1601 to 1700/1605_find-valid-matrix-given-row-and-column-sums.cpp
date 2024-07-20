#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> matrix(n,vector<int>(m));

        // Below commented stuff is incorrect

        // int k = 0;
        // while(k < n*m ){
        //     int minRow = *min_element(rowSum.begin(),rowSum.end());
        //     auto minItRow = distance(rowSum.begin(),find(rowSum.begin(),rowSum.end(),minRow));
        //     int minCol = *min_element(colSum.begin(),colSum.end());
        //     auto minItCol = distance(colSum.begin(),find(colSum.begin(),colSum.end(),minCol));
        //     int min = (minRow<minCol)?minRow:minCol;
        //     rowSum[minItRow] -= min;
        //     if(rowSum[minItRow]==0) rowSum[minItRow] = INT_MAX;
        //     colSum[minItCol] -= min;
        //     if(colSum[minItCol]==0) colSum[minItCol] = INT_MAX;
        //     matrix[minItRow][minItCol] = min;
        //     k++;
        // } 
        // Dont overcomplicate things !!!!
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int min = (rowSum[i]<colSum[j])?rowSum[i]:colSum[j];
                matrix[i][j] = min;
                rowSum[i] -= min;
                colSum[j] -= min;
            }
        return matrix;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}