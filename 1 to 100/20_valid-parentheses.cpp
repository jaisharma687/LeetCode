#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1){
            return false;
        }
        vector<char> stack;
        int top = -1;
        for(int i = 0; i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
            }else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(stack.empty()){
                    return false;
                }
                char t = stack.back();
                if(s[i] == ')' && t != '('){
                    return false;
                }else if(s[i] == ']' && t != '['){
                    return false;
                }else if(s[i] == '}' && t != '{'){
                    return false;
                }
                stack.pop_back();
            }
        }
        if(stack.empty()){
            return true;
        }else return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}