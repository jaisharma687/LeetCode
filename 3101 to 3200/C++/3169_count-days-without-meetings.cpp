#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            vector<vector<int>> merged;
            merged.push_back(meetings[0]);
            int i = 1;
            int n = meetings.size();
            for(;i<n;i++){
                int st = meetings[i][0];
                int ed = meetings[i][1];
                int st_prev = merged.back()[0];
                int ed_prev = merged.back()[1];
                if(st>=st_prev && st<=ed_prev){
                    merged.back()[1] = max(ed_prev,ed);
                }
                else{
                    merged.push_back(meetings[i]);
                }
            }
            int cntDay = days;
            for(auto& meet:merged){
                int st = meet[0];
                int ed = meet[1];
                int d = ed - st + 1;
                cntDay -= d;
            }
            return cntDay;
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