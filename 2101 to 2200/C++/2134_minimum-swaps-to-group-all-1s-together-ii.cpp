#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy = nums;
        nums.insert(nums.end(),copy.begin(),copy.end());
        int k = count(copy.begin(),copy.end(),1);
        if(k==0 || k==n) return 0;
        int left = 0, right = k-1;
        int window = count(copy.begin(),copy.begin()+k,1);
        int m = window;
        while(left<n){
            window += nums[right+1] - nums[left];
            left++,right++;
            m = max(window,m);
        }
        return k-m;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}