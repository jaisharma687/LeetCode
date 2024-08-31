#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        for(int i=0;i<matrix.size();i++){
            if( matrix[i][matrix[0].size()-1] >= target ){
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]==target) found = true;
                }
            }
        }
        return found;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}