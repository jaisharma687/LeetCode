#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int max = -1;
        int s = 0;
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int j=nums[0].size()-1;j>=0;j--){
            for(int i=0;i<nums.size();i++){
                if(max<nums[i][j]) max = nums[i][j];
            }
            s += max;
            max = -1;
        }
        return s;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}