#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end());
            vector<vector<int>> res;
            res.push_back(intervals[0]);
            int i = 1;
            int n = intervals.size();
            for(;i<n;i++){
                int st = intervals[i][0];
                int ed = intervals[i][1];
                int st_prev = res.back()[0];
                int ed_prev = res.back()[1];
                if(st<=ed_prev && st>=st_prev){
                    res.back()[1] = max(ed_prev,ed);
                }
                else{
                    res.push_back(intervals[i]);
                }
            } 
            return res;
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