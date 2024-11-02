#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        long long s = skill[0] + skill[n-1];
        long long l = 1;
        long long r = n-2;
        while(l<r){
            if(s!=skill[l]+skill[r]) return -1;
            l++;
            r--;
        }
        long long chem = 0;
        l = 0;
        r = n-1;
        while(l<r){
            chem += skill[l]*skill[r];
            l++;
            r--;
        }
        return chem;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();