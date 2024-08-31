#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int i=0;
        int n = s.length();
        while(i < n && s[i]==' ') i++;
        if(i==n) return 0;
        if(s[i] == '-' || s[i] == '+') {
            if(s[i]=='-') neg = true;
            i++;
        }
        if(s[i] < '0' || s[i] > '9'){
            return 0;
        }
        while(i < n && s[i]=='0') i++;
        if(i==n) return 0;
        long long int num = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            num = num *10 + (int)(s[i]-'0');
            if(num >= INT_MAX && !neg) return INT_MAX;
            if(num >= pow(2,31) && neg) return -pow(2,31);
            i++;
        }
        return (neg)?-num:num;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}