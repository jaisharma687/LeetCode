#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg++;
            else if(nums[i]>0) pos++; 
        }
        return (pos>neg)?pos:neg;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}