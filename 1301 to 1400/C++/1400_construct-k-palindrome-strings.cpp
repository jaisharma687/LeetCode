#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        vector<int> freq(26,0);
        for(char& x: s){
            freq[x-'a']++;
        }
        int max_palindromes = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2){
                k--;
                freq[i]-=1;
            }
        }
        if(k<0) return false;
        if(k==0) return true;
        for(int i=0;i<26;i++){
            if(freq[i]%2==0){
                k-= freq[i];
                if(k<=0) return true;
            }
        }
        return false;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();