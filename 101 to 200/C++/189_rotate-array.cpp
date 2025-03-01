#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        // Solution 1: One Rotation at a time
        // void leftRotate(vector<int>& nums){
        //     int n = nums.size();
        //     int t = nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //         nums[i] = nums[i-1];
        //     }
        //     nums[0] = t;
        // }
        // void rotate(vector<int>& nums, int k) {
        //     int n = nums.size();
        //     int rotations = k%n;
        //     for(int i=0;i<rotations;i++){
        //         leftRotate(nums);
        //     }
        // }
    
        // Solution 2: Create an array and use distance to place elements
        // void rotate(vector<int>& nums, int k) {
        //     int n = nums.size();
        //     k = k%n;
        //     vector<int> dup = nums;
        //     for(int i=0;i<n;i++){
        //         nums[(i+k)%n] = dup[i];
        //     }
        // }
    
        // Solution 3: Use reverse operation
        void reverse(vector<int>& nums, int left, int right){
            while(left<right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k%n;
            reverse(nums,0,n-1);
            reverse(nums,0,k-1);
            reverse(nums,k,n-1);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}