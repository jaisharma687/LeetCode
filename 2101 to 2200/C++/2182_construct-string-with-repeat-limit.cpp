#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(char x: s){
            freq[x-'a']++;
        }
        string res = "";
        for(int i=25;i>=0;i--){
            while(freq[i]>0){
                char x = i + 'a';
                res += string(min(freq[i],repeatLimit),x);
                freq[i] -= repeatLimit;
                if(freq[i]>0){
                    int j = i-1;
                    while(j>=0 && freq[j]<=0) j--;
                    if(j==-1){
                        return res;
                    }
                    char y = j + 'a';
                    res += y;
                    freq[j]--;
                }
            }
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();