#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid] >= nums[l] && nums[mid] >= nums[r]) l = mid+1;
            else r = mid;
        } 
        return nums[l];
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();