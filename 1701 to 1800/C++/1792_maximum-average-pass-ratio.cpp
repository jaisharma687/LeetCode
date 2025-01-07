#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq;
        for(int i=0;i<classes.size();i++){
            double curr_pr = (double)(classes[i][0])/(classes[i][1]);
            double new_pr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            pq.push({new_pr-curr_pr,i});
        }
        while(extraStudents>0){
            extraStudents--;
            auto curr = pq.top();
            pq.pop();
            classes[curr.second][0] += 1;
            classes[curr.second][1] += 1;
            double curr_pr = (double)(classes[curr.second][0])/(classes[curr.second][1]);
            double new_pr = (double)(classes[curr.second][0]+1)/(classes[curr.second][1]+1);
            pq.push({new_pr-curr_pr,curr.second});
        }
        double res = 0.0;
        for(auto& x: classes){
            res += (double)x[0]/x[1];
        }
        return res/classes.size();
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();