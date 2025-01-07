#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int min = INT_MAX;
        for(auto x:strs) min = (min > x.length()) ? x.length() : min;
        bool common = true;
        while(i<=min && common){
            for(int j=0;j<strs.size()-1;j++) if(strs[j][i] != strs[j+1][i]) common = false;
            if(common == true) i++;
        }
        return strs[0].substr(0,i);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}