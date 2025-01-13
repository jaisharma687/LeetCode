#include "../stdc++.h"
// #include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPrefix(string word, string pref){
        int n = word.size();
        int m = pref.size();
        if(m>n) return false;
        for(int i=0;i<m;i++){
            if(word[i]!=pref[i]){
                return false;
            }
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto& word:words){
            if(isPrefix(word,pref)){
                res++;
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