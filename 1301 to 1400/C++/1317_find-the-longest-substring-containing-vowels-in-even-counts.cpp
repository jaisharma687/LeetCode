#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool checkEven(unordered_map<char,int> m){
        for(auto x: m){
            if(x.second % 2) return false;
        }
        return true;
    }
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> m;
        m.insert({'a',0});
        m.insert({'e',0});
        m.insert({'i',0});
        m.insert({'o',0});
        m.insert({'u',0});
        for(char x: s) if(m.contains(x)) m[x]++;
        if(checkEven(m)) return s.size();
        int window = s.size()-1;
        bool found = false;
         unordered_map<char,int> p = m;
        while(!found){
            int n = s.size();
            m = p;
            while(n!=window){ 
                if(m.contains(s[n-1])) m[s[n-1]]--;
                n--;
            }
            for(int i=0;i+window<=s.size();i++){
                if(i>0){
                    if(m.contains(s[i-1])) m[s[i-1]]--;
                    if(m.contains(s[i+window-1])) m[s[i+window-1]]++;
                }
                if(checkEven(m)){
                    found = true;
                    break;
                }
            }
            if(found) break;
            window--;
        }
        return window;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();