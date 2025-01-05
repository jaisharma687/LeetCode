#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int m = queries.size();
        vector<int> res;
        priority_queue<int> pq;
        for(auto x: queries){
            pq.push(abs(x[0])+abs(x[1]));
            if(pq.size() == k){
                res.push_back(pq.top());
            }
            else if(pq.size()<k){
                res.push_back(-1);
            }
            else{
                pq.pop();
                res.push_back(pq.top());
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