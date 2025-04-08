#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool check(vector<vector<int>> intervals){
            sort(intervals.begin(),intervals.end());
            int sec = 0;
            int mx_end = intervals[0][1];
            int n = intervals.size();
            for(int i=0;i<n;i++){
                int st = intervals[i][0];
                int ed = intervals[i][1];
                if(st>=mx_end){
                    sec++;
                }
                mx_end = max(mx_end,ed);
            }
            return sec>=2;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> x,y;
            for(auto& rect: rectangles){
                x.push_back({rect[0],rect[2]});
                y.push_back({rect[1],rect[3]});
            }
            return check(x) || check(y);
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