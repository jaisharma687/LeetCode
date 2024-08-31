#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = customers[0][0];
        double diff;
        double wait = 0;
        double i = 0;
        for(auto x:customers){
            i++;
            if(time > x[0] || time == customers[0][0]){
                time += x[1];
                wait += time - x[0];
            }else{
                time = x[0]+x[1];
                wait += x[1];
            }
        }
        return wait/i;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}