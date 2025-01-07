#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int MAX = 1e9 + 7;
    int t[100001];
    int solve(int low, int high, int zero, int one,int i){
        if(i>high){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int r1 = solve(low,high,zero,one,i+zero);
        int r2 = solve(low,high,zero,one,i+one);
        return t[i] = (r1 + r2 + ((i>=low)?1:0))%MAX;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(t,-1,sizeof(t));
        return solve(low,high,zero,one,0);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();