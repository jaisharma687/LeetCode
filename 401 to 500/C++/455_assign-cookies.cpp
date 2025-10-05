#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0 || g.size()==0) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int res = 0, j=s.size()-1, i=g.size()-1;
        while(j>=0 && i>=0){
            if(g[i]<=s[j]){
                res++;
                j--;
                i--;
            }else i--;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}