#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            for(int i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i] = nums[i]*2;
                    nums[i+1] = 0;
                }
            }
            int i=0;
            for(int j=0;j<n;j++){
                if(nums[j]!=0){
                    swap(nums[i],nums[j]);
                    i++;
                }
            }
            return nums;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();