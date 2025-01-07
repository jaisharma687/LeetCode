#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char x: s){
            if(x=='D'||x=='B'){
                if(!st.empty()){
                    char p = st.top();
                    if((p=='C'&& x=='D')||(p=='A'&& x=='B')){
                        st.pop();
                    }
                    else{
                        st.push(x);
                    }
                }
                else{
                    st.push(x);
                }
            }
            else{
                st.push(x);
            }
        }
        int len = 0;
        while(!st.empty()){
            st.pop();
            len++;
        }
        return len;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();