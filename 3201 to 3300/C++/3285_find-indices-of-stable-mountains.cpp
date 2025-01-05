#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        for(int i=1;i<height.size();i++){
            if(height[i-1]>threshold) res.emplace_back(i);
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