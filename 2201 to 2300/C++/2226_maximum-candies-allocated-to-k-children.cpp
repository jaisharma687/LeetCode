#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long l = 1;
            long long r = *max_element(candies.begin(),candies.end());
            long long res = 0;
            while(l<=r){
                long long mid = l + (r-l)/2;
                long long cnt = 0;
                for(int x: candies){
                    cnt += x/mid;
                }
                if(cnt >= k){
                    res = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return res;
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