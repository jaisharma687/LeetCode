#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            int i=0,j=0;
            unordered_map<int,int> freq;
            long long res= 0;
            long long pairs=0;
            while(j<n){
                pairs += freq[nums[j]];
                freq[nums[j]]++;
                while(pairs>=k){
                    res += n - j;
                    freq[nums[i]]--;
                    pairs -= freq[nums[i]];
                    i++;
                }
                j++;
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}