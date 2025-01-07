#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    #define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto p = pq.top();
            pq.pop();
            pq.push({p.first*multiplier,p.second});
        }
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            nums[p.second] = p.first;
        }
        return nums;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();