#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxArr = -1;
        for(int i=0;i<arr.size();i++){
            maxArr = max(maxArr,arr[i]);
            if(maxArr==i){
                chunks++;
            }
        }
        return chunks;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();