#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - count(nums.begin(),nums.end(),val);
        while(count(nums.begin(),nums.end(),val) > 0){
            nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        }
        return k;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}