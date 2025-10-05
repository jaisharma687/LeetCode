#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& candidates, int target, int start, vector<int>& temp){
        if(target==0){ 
            res.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            // filtering to prevent same element used twice at same recusrion level twice
            if(i>start && candidates[i-1]==candidates[i]) continue;
            
            // preventing additional recursions;
            if(target-candidates[i]<0) break;
            
            // backtracking and recursion
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}