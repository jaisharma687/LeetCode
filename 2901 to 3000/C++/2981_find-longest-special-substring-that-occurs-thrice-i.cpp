#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isSpecial(string s){
        if(s.size()==1) return true;
        char prev = s[0];
        for(char x: s){
            if(x!=prev) return false;
            prev = x;
        }
        return true;
    }
    bool countSubstr(string s, string p){
        int count = 0;
        size_t pos = s.find(p);
        while(pos!=string::npos){
            count++;
            pos = s.find(p,pos+1);
            if(count == 3) return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int wind = s.size();
        while(wind>=1){
            for(int i=0;i+wind<=s.size();i++){
                string p = s.substr(i,wind);
                if(isSpecial(p)){
                    if(countSubstr(s,p)){
                        return p.size();
                    }
                }
            }
            wind--;
        }
        return -1;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();