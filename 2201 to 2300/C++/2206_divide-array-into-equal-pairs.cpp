#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int,int> mp;
            for(int x: nums){
                mp[x]++;
            }
            for(auto& x: mp){
                if(x.second%2!=0){
                    return false;
                }
            }
            return true;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();