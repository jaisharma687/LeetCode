#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto x: details){
            int s = stoi(x.substr(11,2));
            if(s>60) count++;
        }
        return count;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}