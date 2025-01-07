#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int countOdds(int low, int high) {
        int l = 0;
        for(int i=low;i<=high;i++){
            if(i%2){
                l++;
            }
        }
        return l;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}