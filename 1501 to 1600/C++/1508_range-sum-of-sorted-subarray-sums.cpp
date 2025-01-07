#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> s; 
        for(int k=1;k<=n;k++){
            for(int i=0;i+k<=n;i++){
                int sum = 0;
                for(int j=i;j<i+k;j++){
                    sum += nums[j];
                }
                s.emplace_back(sum);
            }
        }
        sort(s.begin(),s.end());
        int res = 0;
        for(int i = left;i<=right;i++) res += s[i-1], res = res % (int)(pow(10,9)+7);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}