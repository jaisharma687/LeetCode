#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int first=0;
        int val=0;
        for(int i=0;i<n;i++){
            val = val ^ derived[i];
        }
        if(val==first) return true;
        first = 1;
        val = 1;
        for(int i=0;i<n;i++){
            val = val ^ derived[i];
        }
        if(val==first) return true;
        return false;
    }
};

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int val=derived[0];
        for(int i=1;i<n;i++){
            val ^= derived[i];
        }
        if(val==0) return true;
        return false;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();