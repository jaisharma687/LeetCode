#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long l = 0;
            long long r = 1e14;
            while(l<r){
                long long mid = l + (r-l)/2;
                long long repaired_cars = 0;
                for(auto& r: ranks){
                    repaired_cars += sqrt(mid/r);
                }
                if(repaired_cars<cars) l = mid+1;
                else r = mid;
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