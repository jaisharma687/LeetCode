#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    res.push_back({nums[i],nums[l],nums[r]});
                    int lastl = l;
                    int lastr = r;
                    while(l<r && nums[l]==nums[lastl]) l++;
                    while(l<r && nums[r]==nums[lastr]) r--;
                }
                else if(nums[l]+nums[r]>target) r--;
                else l++;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}