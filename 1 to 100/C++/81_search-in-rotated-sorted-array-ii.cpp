#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]==target) return true;
            else if(nums[m]==nums[l] && nums[m]==nums[r]){
                l++;
                r--;
            }
            else if(nums[l]<=nums[m]){
                if(target>=nums[l] && target<nums[m]) r = m-1;
                else l = m+1;
            }else{
                if(target>nums[m] && target<=nums[r]) l = m+1;
                else r = m-1;
            }
        }
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}