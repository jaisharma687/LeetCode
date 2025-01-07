#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        vector<vector<int>> grid(8,vector<int>(8,0));
        for(int i=0;i<8;i+=2)
            for(int j=0;j<8;j+=2)
                grid[i][j] = 1;
        for(int i=1;i<8;i+=2)
            for(int j=1;j<8;j+=2)
                grid[i][j] = 1;
        pair<int,int> c1 = {coordinate1[1]-'1',coordinate1[0]-'a'};
        pair<int,int> c2 = {coordinate2[1]-'1',coordinate2[0]-'a'};
        return grid[c1.first][c1.second] == grid[c2.first][c2.second];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}