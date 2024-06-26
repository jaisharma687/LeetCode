#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        for(int i=2;i<nums.size();i++){
            if(nums[i]+nums[i-1] > nums[i-2] && nums[i-2]+nums[i-1] > nums[i] && 
            nums[i]+nums[i-2] > nums[i-1])
                return nums[i]+nums[i-1]+nums[i-2];
        }
        return 0;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}