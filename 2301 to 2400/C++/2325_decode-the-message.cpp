#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> m;
        unordered_map<char,int> p;
        int i = 0;
        for(auto c : key){
            if(i<26 && p[c]==0 && c !=' '){
                m[c] = i + 'a';
                i++;
                p[c]++;
                if(i==26) break;
            }
        }
        string res = "";
        for(auto x : message){
            if(x != ' ') res.push_back(m[x]);
            else res.push_back(x);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}