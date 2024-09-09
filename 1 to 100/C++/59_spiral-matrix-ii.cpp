#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 1;
        int r_min = 0;
        int c_min = 0;
        int r_max = n-1;
        int c_max = n-1;
        vector<vector<int>> res(n,vector<int>(n,0));
        while(i!=n*n+1){
            for(int col = c_min;col<=c_max && i!=n*n+1;col++){
                res[r_min][col] = i;
                i++;
            }
            r_min++;
            for(int row = r_min;row<=r_max && i!=n*n+1;row++){
                res[row][c_max] = i;
                i++;
            }
            c_max--;
            for(int col=c_max;col>=c_min && i!=n*n+1;col--){
                res[r_max][col] = i;
                i++;
            }
            r_max--;
            for(int row=r_max;row>=r_min && i!=n*n+1;row--){
                res[row][c_min] = i;
                i++;
            }
            c_min++;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}