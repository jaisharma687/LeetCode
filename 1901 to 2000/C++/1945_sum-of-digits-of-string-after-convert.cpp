#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int operation(string s){
        int sum = 0;
        for(char x:s){
            sum += (int)(x-'0');
        }
        return sum;
    }
    string toString(int n){
        string res = "";
        while(n>0){
            char t = (char)(n%10 + '0');
            n/=10;
            res = t + res;
        }
        return res;
    }
    int getLucky(string s, int k) {
        int sum = 0;
        for(char x:s){
            int r = (int)(x-'a')+1;
            sum += r%10 + r/10;
        }
        if(k==1) return sum;
        string res = toString(sum);
        k--;
        while(k>0){
            int r = operation(res);
            if(k==1) return r;
            res = toString(r);
            k--;
        }
        return -1;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}