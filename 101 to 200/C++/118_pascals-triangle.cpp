#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> pasTri;
            for(int i=0;i<numRows;i++){
                pasTri.push_back(vector<int>(i+1,1));
                for(int j=1;j<i;j++){
                    pasTri[i][j] = pasTri[i-1][j-1] + pasTri[i-1][j];
                }
            }
            return pasTri;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();