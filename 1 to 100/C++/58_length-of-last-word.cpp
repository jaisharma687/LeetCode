#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i>=0 && s[i] == ' '){
            i--;
        }
        int j = 0;
        while(i>=0 && s[i] != ' '){
            i--;
            j++;
        }
        return j;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}