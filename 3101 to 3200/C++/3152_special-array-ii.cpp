#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pivots(n,0);
        for(int i=1;i<n;i++){
            pivots[i] = pivots[i-1];
            if(nums[i]%2==nums[i-1]%2){
                pivots[i]++;
            }
        }
        vector<bool> ans;
        for(auto& query: queries){
            int l = query[0];
            int r = query[1];
            int falseCount = pivots[r] - ( l > 0 ? pivots[l] : 0);
            if(falseCount && l != r) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();