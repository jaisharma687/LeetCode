#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] && nums[2] + nums[1] > nums[0]){
            if(nums[0] == nums[1] && nums[2] == nums[1]) return "equilateral";
            else if(nums[0] != nums[1] && nums[1] != nums[2] && nums[2] != nums[0]) return "scalene";
            else return "isosceles";
        }else return "none";
    }
};

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[2];
        int b = nums[1];
        int c = nums[0];
        if(a>=b+c) return "none";
        if(a==c) return "equilateral";
        if(a==b || b==c) return "isosceles";
        return "scalene";

    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}