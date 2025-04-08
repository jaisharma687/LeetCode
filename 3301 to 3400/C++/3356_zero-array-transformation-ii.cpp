#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool canFormZeroArray(vector<int>& nums, vector<vector<int>> queries, int k){
            int n = nums.size();
            int sum = 0;
            vector<int> diffArr(n+1,0);
            for(int q=0;q<k;q++){
                int l = queries[q][0];
                int r = queries[q][1];
                int val = queries[q][2];
                diffArr[l] += val;
                diffArr[r+1] -= val;
            }
            for(int i=0;i<n;i++){
                sum += diffArr[i];
                if(sum<nums[i]) return false;
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int l = 0;
            int r = queries.size();
            if(!canFormZeroArray(nums,queries,r)) return -1;
    
            while(l<=r){
                int mid = l + (r-l)/2;
                if(canFormZeroArray(nums,queries,mid)){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
    
            return l;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();