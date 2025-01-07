#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void solve(vector<int>& nums,vector<bool> visited,set<vector<int>>& res, vector<int> curr){
        if(curr.size()==nums.size()){
            res.insert(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i] = true;
                curr.push_back(nums[i]);
                solve(nums,visited,res,curr);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        set<vector<int>> res;
        solve(nums,visited,res,{});
        return vector<vector<int>>(res.begin(),res.end());
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();