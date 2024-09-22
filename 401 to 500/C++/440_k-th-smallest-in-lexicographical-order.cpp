#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long min(long long a, long long b){
        return (a<b)?a:b;
    }
    long long stepCount(long long cur,int n){
        long long steps = 0;
        long long nei = cur + 1;
        while(cur<=n){
            steps += min(n+1,nei) - cur;
            cur *= 10;
            nei *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long long cur = 1;
        int i = 1;
        while(i<k){
            long long steps = stepCount(cur,n);
            if(i + steps <= k){
                i += steps;
                cur++;
            }
            else{
                cur *= 10;
                i += 1;
            }
        }
        return (int)cur;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();