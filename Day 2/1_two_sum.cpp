#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        for(int i=0;i<l-1;i++){
            int temp = nums[i];
            for(int j = i+1;j<l;j++){
                if(temp + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
    vector<int> k = {2,7,11,15};
    vector<int> res = obj.twoSum(k,9);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}