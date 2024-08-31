#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> p;
        for(auto x:s){
            if(x!=')') p.push_back(x);
            else{
                vector<char> temp;
                while(p.size()>0 && p.back() != '('){
                    temp.push_back(p.back());
                    p.pop_back();
                }
                p.pop_back();
                for(auto t:temp) p.push_back(t);
            }
        }
        string out = "";
        while(p.size()!=0) out = p.back() + out, p.pop_back();
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}