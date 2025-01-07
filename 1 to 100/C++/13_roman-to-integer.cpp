#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        int value = 0;
        for(int i = 0; i<s.length();i++){
            if(i < s.length() -1 && romanMap[s[i]] < romanMap[s[i+1]]){
                value -= romanMap[s[i]];
            }else{
                value += romanMap[s[i]];
            }
        }
        return value;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}