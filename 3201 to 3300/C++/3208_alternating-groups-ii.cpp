#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            for(int i=0;i<k;i++){
                colors.push_back(colors[i]);
            }
            int cnt = 0;
            int i=0;
            int j=1;
            while(j<(n+k-1)){
                if(colors[j]==colors[j-1]){
                    i = j;
                    j++;
                    continue;
                }
                if(j-i+1==k){
                    cnt ++;
                    i++;
                }
                j++;
            }
            return cnt;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();