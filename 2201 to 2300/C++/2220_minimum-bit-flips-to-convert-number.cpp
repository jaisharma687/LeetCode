#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string toBinary(int n){
        string res = "";
        while(n>0){
            char t = (char)(n%2 + '0');
            res = t + res;
            n /= 2;
        }
        return res;
    }
    int minBitFlips(int start, int goal) {
        string st = toBinary(start);
        string gl = toBinary(goal);
        while(gl.size()<st.size()){
            gl = "0" + gl;
        }
        while(gl.size()>st.size()){
            st = "0" + st;
        }
        int n = st.size();
        int flips = 0;
        for(int i=0;i<n;i++){
            if(gl[i]!=st[i]) flips++;
        }
        return flips;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}