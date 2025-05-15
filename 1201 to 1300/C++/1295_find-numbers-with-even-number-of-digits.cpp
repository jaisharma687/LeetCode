#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
             int cnt = 0;
             for(int x: nums){
                int n = log10(x)+1;
                if(n%2==0) cnt++;
             }
             return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}