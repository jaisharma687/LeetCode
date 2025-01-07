#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(auto x : logs){
            if(level != 0 && x == "../") level--;
            else if(x == "./" || x=="../") continue;
            else level++;
        }
        return level;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}