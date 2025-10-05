#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int solveBinary(vector<int>& nums, int l, int r,int target){
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = n-1;
        while(l<r){
            int mid = l + (r - l) / 2;
            if(nums[mid]>nums[r]) l = mid+1;
            else r = mid;
        }
        int pvt = l;
        int idx = solveBinary(nums,0,pvt-1,target);
        if(idx!=-1) return idx;
        return solveBinary(nums,pvt,n-1,target);
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]<nums[0]) r = mid-1;
            else l = mid+1;
        }
        int pivot = l;
        l = 0;
        r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int realMid = (mid+pivot)%n;
            if(nums[realMid]==target) return realMid;
            else if(nums[realMid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();