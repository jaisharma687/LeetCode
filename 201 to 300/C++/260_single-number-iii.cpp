#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> output;
        for(int i=0;i<nums.size();i++){
            if(count(nums.begin(),nums.end(),nums[i])==1){
                output.push_back(nums[i]);
            }
        }
        return output;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}