#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int solvable(vector<int> piles, int k, int h){
        int hrs = 0;
        for(int x: piles){
            hrs +=  ceil((double)x/k);
        }
        return h - hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<r){
            int mid = (l+r)/2;
            int hrs = solvable(piles,mid,h);
            if(hrs>=0) r = mid;
            else if(hrs<0) l = mid+1;
        }
        return l;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();