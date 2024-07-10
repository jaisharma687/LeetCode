#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int totalMoney(int n) {
        int diff = 0;
        int amt = 0;
        for(int i=0; i<n;i++){
            int day = i % 7;
            if(day == 0) diff++;
            amt += day + diff;
        }
        return amt;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}