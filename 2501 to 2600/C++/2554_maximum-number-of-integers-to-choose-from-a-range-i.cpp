#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> arr(n);
        for(int i=0;i<n;i++) arr[i] = i+1;
        for(int b: banned){
            if(b<=n) arr[b-1]=-1;
        }
        int count = 0;
        for(int x: arr){
            if(x!=-1){
                if(maxSum-x>=0){
                    maxSum -= x;
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();