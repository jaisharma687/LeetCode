#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int direction(int dir){
        return dir % 4;
    }
    bool isRobotBounded(string instructions) {
        int dir = 0; //0-North,1-west,2-south,3-east
        int x = 0;
        int y = 0;
        for(int i=0;i<instructions.size();i++){
            if(instructions[i] == 'R'){
                dir += 3;
            }else if(instructions[i] == 'L'){
                dir += 1;
            }else if(dir == 0 && instructions[i] == 'G'){
                y++;
            }else if(dir == 1 && instructions[i] == 'G'){
                x++;
            }else if(dir == 2 && instructions[i] == 'G'){
                y--;
            }else if(dir == 3 && instructions[i] == 'G'){
                x--;
            }
            dir = direction(dir);
        }
        if(dir == 1 || dir == 2 || dir == 3 || (dir == 0 && x==0 && y==0)){
            return true;
        }
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}