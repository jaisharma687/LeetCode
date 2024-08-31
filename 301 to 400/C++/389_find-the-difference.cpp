#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod = 1e9+7;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_ascii = 0;
        int t_ascii = 0;
        for(int i=0;i<s.length();i++){
            s_ascii += int(s[i]);
            t_ascii += int(t[i]);
        }
        t_ascii += int(t[s.length()]);
        return char(t_ascii-s_ascii);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}