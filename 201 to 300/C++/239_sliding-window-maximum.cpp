#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++) pq.push({nums[i],i});
        vector<int> res(n-k+1);
        res[0] = pq.top().first;
        for(int i=1;i<=n-k;i++){
            while(!pq.empty() && pq.top().second<i) pq.pop();
            pq.push({nums[k+i-1],k+i-1});
            res[i] = pq.top().first;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}