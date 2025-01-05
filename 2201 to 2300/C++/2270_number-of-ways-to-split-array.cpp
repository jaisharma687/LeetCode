#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int totalSum = 0;
        for(int x: nums){
            totalSum += x;
        }
        long long int currSum = 0;
        int splits = 0;
        for(int i=0;i<n-1;i++){
            currSum += nums[i];
            if(currSum >= (totalSum - currSum)){
                splits++;
            }
        }
        return splits;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();