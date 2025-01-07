#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target,vector<vector<int>>& res,vector<int> temp ,int start){
        if(target == 0) res.push_back(temp);
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i>start && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],res,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int current_sum = 0;
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates,target,res,temp,0);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}