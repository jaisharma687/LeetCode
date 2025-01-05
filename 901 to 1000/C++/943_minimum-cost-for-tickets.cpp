#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int dp[365];
//     int solve(vector<int>& days, vector<int>& costs, int i){
//         if(i>=days.size()){
//             return 0;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int j = i;
//         int cost1 = costs[0] + solve(days,costs,i+1);
//         while(j<days.size() && days[j]<days[i]+7) j++;
//         int cost7 = costs[1] + solve(days,costs,j);
//         while(j<days.size() && days[j]<days[i]+30) j++;
//         int cost30 = costs[2] + solve(days,costs,j);
//         return dp[i] = min(cost1,min(cost7,cost30));
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         memset(dp,-1,sizeof(dp));
//         return solve(days,costs,0);
//     }
// };

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n-1];
        vector<int> dp(lastDay+1); // dp[i] means the total cost to reach day i;
        unordered_set<int> day;
        for(int x: days){
            day.insert(x);
        }
        dp[0] = 0;
        for(int i=1;i<=lastDay;i++){
            if(day.find(i)==day.end()){
                dp[i] = dp[i-1];
            }else{
                int cost1,cost7,cost30;
                cost1 = costs[0] + dp[i-1];
                cost7 = costs[1] + dp[max(i-7,0)];
                cost30 = costs[2] + dp[max(i-30,0)];
                dp[i] = min(cost1,min(cost7,cost30));
            }
        }
        return dp[lastDay];
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();