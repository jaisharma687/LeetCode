#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Brute Force
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

// Binary Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row =0;
        vector<int> arr(m,0);
        for(int i=0;i<m;i++) arr[i]=matrix[i][n-1];
        while(row<m && arr[row]<target) row++;
        if(row==m) return false;
        int l =0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[row][mid]<target) l = mid+1;
            else if(matrix[row][mid]>target) r = mid-1;
            else return true;
        }
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}