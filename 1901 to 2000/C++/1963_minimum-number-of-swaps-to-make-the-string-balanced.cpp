#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minSwaps(string s){
        stack<char> st;
        for(char x: s){
            if(!st.empty() && x==']'){
                if(st.top()=='['){
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
        int count = 0;
        while(!st.empty() && st.top()=='['){
            count++;
            st.pop();
        }
        return (count%2==0)?(count/2):((count+1)/2);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();