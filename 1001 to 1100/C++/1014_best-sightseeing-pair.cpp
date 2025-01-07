#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(!pq.empty()){
                ans = max(ans,pq.top()+values[i]-i);
            }
            pq.push(values[i]+i);
        }
        return ans;

    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();