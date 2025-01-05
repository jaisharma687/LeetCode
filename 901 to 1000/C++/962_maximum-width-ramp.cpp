#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxRamp = 0;
        int n = nums.size();
        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxRight[i] = max(nums[i],maxRight[i+1]);
        }
        int i=0;
        int j=0;
        while(j<n){
            if(nums[i]>maxRight[j]){
                i++;
            }
            maxRamp = max(maxRamp,j-i);
            j++;
        }
        return maxRamp;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();