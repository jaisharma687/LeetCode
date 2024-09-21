#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int val = 1;
        while(res.size() != n){
            res.push_back(val);
            if(val * 10 <= n){
                val *= 10;
            }
            else{
                while(val == n || val % 10 == 9) val = val / 10;
                val++;
            }
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