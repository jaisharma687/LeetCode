#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n,0);
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] ^ arr[i];
        }
        vector<int> res;
        for (auto x : queries) {
            int left = x[0];
            int right = x[1];
            if(left==0) res.push_back(pre[right]);
            else res.push_back(pre[right]^pre[left-1]);
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();