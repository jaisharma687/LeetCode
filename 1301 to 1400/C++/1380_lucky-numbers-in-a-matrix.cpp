#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxCol(vector<vector<int>> matrix, int col){
        int max = matrix[0][col];
        for(int i=1;i<matrix.size();i++){
            if(max<matrix[i][col]) max = matrix[i][col];
        }
        return max;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;
        unordered_set<int> max;
        for(int i=0;i<matrix[0].size();i++){
            max.insert(maxCol(matrix,i)); 
        }
        for(int i=0;i<matrix.size();i++){
            int min = *min_element(matrix[i].begin(),matrix[i].end());
            if(max.find(min) != max.end()) lucky.push_back(min);
        }
        return lucky;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}