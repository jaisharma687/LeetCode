#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> t(3,vector<int>(3,-1));
        for(int i=0;i<moves.size();i++){
            int row = moves[i][0];
            int col = moves[i][1];
            t[row][col] = (i%2) ? 0 : 1;
        }
        vector<vector<int>> solution{{0,1,2},{0,11,22},{0,10,20},{10,11,12},{20,21,22},{2,11,20},{1,11,21},{2,12,22}};
        for(int i=0;i<8;i++){
            int x = solution[i][0];
            int y = solution[i][1];
            int z = solution[i][2];
            int x1 = x%10; // col
            int x2 = x/10; //row
            int y1 = y%10; // col
            int y2 = y/10; //row
            int z1 = z%10; // col
            int z2 = z/10; //row
            int sx = t[x2][x1];
            int sy = t[y2][y1];
            int sz = t[z2][z1];
            if(sx == 1 && sy == 1 && sz == 1){
                return "A";
            }else if(sx == 0 && sy == 0 && sz == 0){
                return "B";
            }
        }
        if(moves.size() < 9){
            return "Pending";
        }
        return "Draw";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}