#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        void reverse(vector<int>& nums, int bpt){
            int n = nums.size();
            int l = bpt;
            int r = n-1;
            while(l<r){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            return;
        }
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int breakPt = -1;
            for(int i = n-2;i>=0;i--){
                if(nums[i]<nums[i+1]){
                    breakPt = i;
                    break;
                }
            }
            cout<<breakPt<<endl;
            if(breakPt==-1){
                reverse(nums,0);
                return;
            }
            for(int i=n-1; i>breakPt;i--){
                if(nums[i]>nums[breakPt]){
                    swap(nums[i],nums[breakPt]);
                    break;
                }
            }
            reverse(nums,breakPt+1);
            return;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();