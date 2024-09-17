#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    unordered_map<string,int> m;
    void tokenize(string s){
        int left = 0;
        int right = 0;
        for(int i=0;i<s.size();i++){
            char x = s[i];
            if(x==' '){
                m[s.substr(left,right-left)]++;
                left = i+1;
                right = i+1;
            }else right++;
        }
        m[s.substr(left,right-left)]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        tokenize(s1);
        tokenize(s2);
        vector<string> res;
        for(auto x:m){
            if(x.second==1) res.push_back(x.first);
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