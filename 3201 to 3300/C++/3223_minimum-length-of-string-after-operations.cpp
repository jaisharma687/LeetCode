#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        int ans = 0;
        for(char x: s){
            freq[x-'a']++;
        }
        for(int i=0;i<26;i++){
            while(freq[i]>2){
                freq[i]-=2;
            }
            ans += freq[i];
        }
        return ans;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();