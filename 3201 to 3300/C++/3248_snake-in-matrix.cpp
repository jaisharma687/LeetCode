#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<int> start = {0,0};
        for(auto x:commands){
            if(x=="RIGHT") start[1]++;
            else if(x=="LEFT") start[1]--;
            else if(x=="UP") start[0]--;
            else if(x=="DOWN") start[0]++;
        }
        return start[0]*n+start[1];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}