#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        for(char x: s){
            if(x=='1') ones++;
        }
        int zeros = n-ones;
        int left=0;
        int right=ones;
        int mx = -1;
        int i = 0;
        while(i<n-1){ 
            left = (s[i]=='0')?left+1:left;
            right = (s[i]=='0')?right:right-1;
            mx = max(mx,left+right);
            i++;
        }
        return mx;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();