#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxEle = 0, maxVal = 0, maxDiff = 0;
            for(int x: nums){
                maxVal = max(maxVal, x*maxDiff);
                maxDiff = max(maxDiff, maxEle-x);
                maxEle = max(maxEle, (long long)x);
            }
            return maxVal;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();