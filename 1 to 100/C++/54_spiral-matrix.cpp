#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        int right = 0,left = matrix[0].size()-1,top = 0,bottom = matrix.size()-1;
        int n = (left+1)*(bottom+1);
        while(true){
            for(int j=right;j<=left;j++){
                sol.emplace_back(matrix[top][j]);
                n--;
            }
            top++;
            if(n==0) break;
            for(int i=top;i<=bottom;i++){
                sol.emplace_back(matrix[i][left]);
                n--;
            }
            left--;
            if(n==0) break;
            for(int j=left;j>=right;j--){
                sol.emplace_back(matrix[bottom][j]);
                n--;
            }
            bottom--;
            if(n==0) break;
            for(int i=bottom;i>=top;i--){
                sol.emplace_back(matrix[i][right]);
                n--;
            }
            right++;
            if(n==0) break;
        }
        return sol;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}