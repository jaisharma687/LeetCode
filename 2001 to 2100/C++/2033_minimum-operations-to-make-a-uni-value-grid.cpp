#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int k) {
            vector<int> elements;
            for(auto& x: grid){
                for(int y: x){
                    elements.push_back(y);
                }
            }
            sort(elements.begin(),elements.end());
            int n = elements.size();
            int median = elements[n/2];
            int ops = 0;
            for(int x: elements){
                if(x%k != median%k) return -1;
                ops += abs(median - x)/ k;
            }
            return ops;
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