#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(begin(nums),end(nums));
        int res = 0;
        int m = 0;
        int c = count(nums.begin(),nums.end(),mx);
        if(c==1) return 1;
        else if(c==nums.size()) return nums.size();
        else{
            for(int x: nums){
                if(x==mx) m++;
                else{
                    res = max(m,res);
                    m = 0;
                }
            }
        }
        res = max(m,res);
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();