#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int power(vector<int> nums, int start, int k){
        bool sorted = true;
        for(int i=start+1;i<start+k;i++){
            if(nums[i]-nums[i-1]!=1){
                sorted = false;
                break;
            }
        }
        if(sorted) return nums[start+k-1];
        else return -1;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1,0);
        for(int i=0;i<=n-k;i++){
            res[i] = power(nums,i,k);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}