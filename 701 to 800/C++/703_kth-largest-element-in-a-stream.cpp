#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int s;
    Solution(int k, vector<int>& nums) {
        s = k;
        for(auto x: nums) pq.push(x);
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>s) pq.pop();
        return pq.top();
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}