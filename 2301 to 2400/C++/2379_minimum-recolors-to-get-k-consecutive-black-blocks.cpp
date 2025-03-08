#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            int cntW = 0;
            for(int i=0;i<k;i++){
                if(blocks[i]=='W'){
                    cntW++;
                }
            }
            int minW = cntW;
            for(int i=1;i+k<=n;i++){
                if(blocks[i-1]=='W'){
                    cntW--;
                }
                if(blocks[i+k-1]=='W'){
                    cntW++;
                }
                minW=min(minW,cntW);
            }
            return minW;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();