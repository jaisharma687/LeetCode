#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        for(int i=0;i<l-1;i++){
            int temp = nums[i];
            for(int j = i+1;j<l;j++){
                if(temp + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};