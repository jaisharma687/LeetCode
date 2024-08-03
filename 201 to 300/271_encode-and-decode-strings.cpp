#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res= "";
        for(auto x:strs){
            res += to_string(x.size()) + "#" + x;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            int n = 0;
            while(s[i]<='9' && s[i]>='0') n = n*10 + (int)(s[i++] - '0');
            i++;//s[i] == '#'
            string str = s.substr(i,n);
            res.push_back(str);
            i+=n;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}