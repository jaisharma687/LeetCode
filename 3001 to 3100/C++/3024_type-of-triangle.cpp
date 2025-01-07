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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}