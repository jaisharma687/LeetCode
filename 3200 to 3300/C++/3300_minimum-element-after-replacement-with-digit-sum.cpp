#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int replacements(int n){
        string nStr = to_string(n);
        int res = 0;
        for(char x: nStr){
            res += x - '0';
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = replacements(nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();