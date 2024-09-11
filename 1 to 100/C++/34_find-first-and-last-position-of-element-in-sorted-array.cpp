#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int right = nums.size()-1;
        int left = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                int l = mid;
                int r = mid;
                while(l>=0 && nums[l]==target){
                    l--;
                }
                while(r<nums.size() && nums[r]==target){
                    r++;
                }
                res={l+1,r-1};
                break;
            }
        }
        if(res.size()==0) return {-1,-1};
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}