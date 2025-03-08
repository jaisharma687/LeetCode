#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        // Solution 1:
        // vector<int> pivotArray(vector<int>& nums, int pivot) {
        //     int equals = 0;
        //     vector<int> res;
        //     for(int x: nums){
        //         if(x<pivot){
        //             res.push_back(x);
        //         }
        //         if(x==pivot) equals++;
        //     }
        //     while(equals--){
        //         res.push_back(pivot);
        //     }
        //     for(int x: nums){
        //         if(x>pivot){
        //             res.push_back(x);
        //         }
        //     }
        //     return res;
        // }
    
        // Solution 2: Two Pointers
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int> res(n,-1);
            int left = 0;
            int right = n-1;
            for(int i=0,j=n-1;i<n;i++,j--){
                if(nums[i]<pivot){
                    res[left] = nums[i];
                    left++;
                }
                if(nums[j]>pivot){
                    res[right] = nums[j];
                    right--;
                }
            }
            while(left<=right){
                res[left++] = pivot;
            }
            return res;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();