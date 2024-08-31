#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int hammingWeight(int n) {
        int set = 0;
        while(n!=0){
            int rem = n%2;
            if(rem) set++;
            n /= 2;
        }
        return set;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}