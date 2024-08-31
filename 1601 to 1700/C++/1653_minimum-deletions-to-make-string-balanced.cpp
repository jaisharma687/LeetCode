#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minimumDeletions(string s) {
        vector<pair<int,int>> e;
        int a=0,b=0;
        for(auto x: s){
            if(x=='a') a++;
            if(x=='b') b++;
            e.push_back({a,b}); 
        }
        int min = INT_MAX;
        for(int i=0;i<s.size();i++){
            int count_b_left = (i>0) ? e[i-1].second : 0;
            int count_a_right = a - e[i].first;
            int m = count_b_left + count_a_right;
            if(min>m) min = m;
        }
        return min;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}