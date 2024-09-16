#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


// not optimal solution
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

// bit masking
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> m;
        m.insert({0,-1});
        int mask = 0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') mask ^= 1<<0;
            else if(s[i]=='e') mask ^= 1<<1;
            else if(s[i]=='i') mask ^= 1<<2;
            else if(s[i]=='o') mask ^= 1<<3;
            else if(s[i]=='u') mask ^= 1<<4;
            if(m.contains(mask)){
                res = max(res,i-m[mask]);
            }
            else m[mask] = i;
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