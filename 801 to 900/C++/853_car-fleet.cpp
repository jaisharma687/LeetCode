#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        for(int i=0;i<speed.size();i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end(),[](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });
        stack<pair<int,int>> st;
        for(pair<int,int> &p: ps){
            if(st.size()==0) st.push(p);
            else{
                pair<int,int> p2 = st.top();
                double t1 = (double)(target-p.first)/p.second;
                double t2 = (double)(target-p2.first)/p2.second;
                if(t1 > t2) st.push(p);
            }
        }
        return st.size();
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();