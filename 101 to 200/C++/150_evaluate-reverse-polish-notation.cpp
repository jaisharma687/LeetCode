#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int strToNum(string s){
        if(s[0]!='-'){
            int n = 0;
            for(auto x:s){
                n = n*10 + (int)(x-'0');
            }
            return n;
        }
        else{
            int n = 0;
            for(int i=1;i<s.size();i++){
                n = n*10 + (int)(s[i]-'0');
            }
            return -n;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x: tokens){
            if(x=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b+a);
            }
            else if(x=="-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if(x=="*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);
            }
            else if(x=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else{
                int n = strToNum(x);
                st.push(n);
            }
        }
        return st.top();
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}