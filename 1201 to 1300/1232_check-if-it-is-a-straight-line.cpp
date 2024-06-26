#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    double slope(int x1,int y1,int x2,int y2){
        if(x2==x1) return 1;
        return (y2-y1)/(x2-x1);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double d = slope(coordinates[0][0],coordinates[0][1],coordinates[1][0],coordinates[1][1]);
        for(int i=0;i<coordinates.size()-1;i++){
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            for(int j=i+1;j<coordinates.size();j++){
                int x2 = coordinates[j][0];
                int y2 = coordinates[j][1];
                if(d != slope(x1,y1,x2,y2)){
                    return false;
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