#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0,d=0,l=0,r=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i] == 'U'){
                u++;
            }else if(moves[i] == 'D'){
                d++;
            }else if(moves[i] == 'R'){
                r++;
            }else if(moves[i] == 'L'){
                l++;
            }
        }
        if(u==d && r==l){
            return true;
        }else{
            return false;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}