#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pdt = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                pdt *= -1;
            }else if(nums[i] == 0){
                return 0;
            }
        }
        return pdt;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}