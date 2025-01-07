#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<bool> marked(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int sc = curr.first;
            int idx = curr.second;
            if(!marked[idx]){
                score += sc;
                marked[idx] = true;
                if(idx>0){
                    marked[idx-1] = true;
                }
                if(idx<n-1){
                    marked[idx+1] = true;
                }
            }
        }
        return score;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();