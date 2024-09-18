#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b){
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa; 
        });
        if(nums[0] == 0) return "0";
        string res = "";
        for(int num: nums){
            res += to_string(num);
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