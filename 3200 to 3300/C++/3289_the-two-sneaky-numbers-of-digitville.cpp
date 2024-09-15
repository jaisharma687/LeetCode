#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        for(int x: nums){
            if(count(nums.begin(),nums.end(),x)==2 && find(res.begin(),res.end(),x)==res.end()){
                res.push_back(x);
            }
            if(res.size()==2) break;
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