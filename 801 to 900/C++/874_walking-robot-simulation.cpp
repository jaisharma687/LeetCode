#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<long long,long long>> pairs;
        for(auto x:obstacles){
            pairs.insert({x[0],x[1]});
        }
        pair<long long,long long> cur = {0,0};
        int dir = 0; // 0 - North, 1 - East, 2 - South, 3 - West
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        long long m = 0;
        for(auto x : commands){
            switch(x){
                case -1:
                    dir = (dir+1)%4;
                    break;
                case -2:
                    dir = (dir+3)%4;
                    break;
                default:
                    for(int i=1;i<=x;i++){
                        int cx = cur.first + dx[dir];
                        int cy = cur.second + dy[dir];
                        if(pairs.find({cx,cy})==pairs.end()){
                            cur = {cx,cy};
                            m = max(m,(long long)pow(cx,2)+(long long)pow(cy,2));
                        }
                        else break;
                    }
            }
        }
        return m;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}