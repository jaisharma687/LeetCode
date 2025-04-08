#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     long long t[100001];
//     long long recursion(vector<vector<int>>& questions, int i){
//         int n = questions.size();
//         if(i>=n){
//             return 0;
//         }
//         if(t[i]!=0){
//             return t[i];
//         }
//         return t[i] = max(recursion(questions,i+1),questions[i][0] + recursion(questions,i+1+questions[i][1]));
//     }
//     long long mostPoints(vector<vector<int>>& questions) {
//         memset(t,0,sizeof(t));
//         return recursion(questions,0);
//     }
// };

class Solution {
    public:
        long long t[100001];
        long long mostPoints(vector<vector<int>>& questions) {
            memset(t,0,sizeof(t));
            int  n = questions.size();
            for(int i=n-1;i>=0;i--){
                int j = i+questions[i][1]+1;
                long long val = questions[i][0] + (j<n ? t[j] : 0);
                t[i] = max(t[i+1],val);
            }
            return t[0];
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