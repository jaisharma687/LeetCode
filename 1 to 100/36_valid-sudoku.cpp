#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    m[board[i][j]]++;
                    if(m[board[i][j]]==2) return false;
                }
            }
        }
        for(int j=0;j<9;j++){
            unordered_map<char,int> m;
            for(int i=0;i<9;i++){
                if(board[i][j] != '.'){
                    m[board[i][j]]++;
                    if(m[board[i][j]]==2) return false;
                }
            }
        }
        vector<int> rStart={0,3,6};
        vector<int> cStart={0,3,6};
        for(int k = 0;k<3;k++){
            for(int l =0;l<3;l++){
                unordered_map<char,int> m;
                for(int i=rStart[k];i<rStart[k]+3;i++){
                    for(int j=cStart[l];j<cStart[l]+3;j++){
                    if(board[i][j] != '.'){
                        m[board[i][j]]++;
                        if(m[board[i][j]]==2) return false;
                    }
                }
            }
            }
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}