#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        void transpose(vector<vector<int>>& matrix){
            int n = matrix.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        void reverse(vector<int>& row){
            int n = row.size();
            int i=0,j=n-1;
            while(i<j){
                swap(row[i],row[j]);
                i++;
                j--;
            }
        }
        void rotate(vector<vector<int>>& matrix) {
            transpose(matrix);
            int n = matrix.size();
            for(int i=0;i<n;i++){
                reverse(matrix[i]);
            }
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();