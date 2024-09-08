#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int toInt(string s){
        int n = 0;
        for(char x: s){
            n = n*10 + (int)(x-'0');
        }
        return n;
    }
    string toBinary(string s){
        int n = toInt(s);
        string res = "";
        while(n>0){
            char t = (n%2)+'0';
            res = t + res;
            n /= 2;
        }
        return res;
    }
    string convertDateToBinary(string date) {
        string year = toBinary(date.substr(0,4));
        string month = toBinary(date.substr(5,2));
        string day = toBinary(date.substr(8,2));
        return year + "-" + month + "-" + day;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}