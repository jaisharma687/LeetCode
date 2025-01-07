#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string generateString(string s){
        string p = s;
        for(char x: p){
            if(x>='a' && x<='y'){
                int t = x - 'a';
                char temp = ((t + 1) + 'a');
                s += temp;
            }
            else if(x=='z') s+= 'a';
        }
        return s;
    }
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<=k){
            s = generateString(s);
        }
        return s[k-1];
    }
};