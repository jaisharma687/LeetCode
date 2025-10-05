#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            int count = r - mid; 
            if(nums[mid]==nums[mid+1]){
                if(count%2==0) l = mid+2;
                else r = mid -1;
            }else{
                if(count%2==0) r = mid;
                else l = mid+1;
            }
        }
        return nums[l];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int& x: nums) res ^= x;
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}