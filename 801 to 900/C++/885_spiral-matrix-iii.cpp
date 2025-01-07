#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int step = 0;
        vector<vector<int>> res;
        int r=rStart,c=cStart;
        int dir = 0;// 0-right, 1-down, 2-left, 3-up
        int n = rows*cols;
        while(res.size()<n){
            if(dir % 2 == 0) step++;
            for(int i=0;i<step;i++){
                if(r>=0 && r<rows && c>=0 && c<cols) res.push_back({r,c});
                if(dir == 0) c++;
                else if(dir == 1) r++;
                else if(dir == 2) c--;
                else if(dir == 3) r--;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}