#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            int pt1=0;
            for(int pt2=1;pt2<n;pt2++){
                if(nums[pt1]!=nums[pt2]){
                    pt1++;
                    nums[pt1]=nums[pt2];
                }
            }
            return pt1+1;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();