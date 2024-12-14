#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 1;
        for(int i=0;i<nums.size();i++){
            int l = 0;
            int r = nums.size()-1;
            int val = nums[i]+2*k;
            int ub = -1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums[mid]<=val){
                    ub = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            res = max(res,ub-i+1);
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