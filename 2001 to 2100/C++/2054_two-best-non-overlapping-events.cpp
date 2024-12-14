#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {endtime, val}
        sort(events.begin(),events.end());
        int maxSum = 0;
        int maxVal = 0;
        for(auto& event: events){
            while(pq.size() && pq.top().first < event[0]){
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            maxSum = max(maxSum,maxVal + event[2]);
            pq.push({event[1],event[2]});
        }
        return maxSum;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();