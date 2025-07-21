#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> res;
        vector<int> keyIdx;
        for(int j=0;j<n;j++){
            if(nums[j]==key){
                keyIdx.push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j: keyIdx){
                if(abs(i-j)<=k){
                    res.insert(i);
                }
            }
        }
        vector<int> out(res.begin(),res.end());
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}