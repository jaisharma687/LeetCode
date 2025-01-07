#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int xorOperation(int n, int start) {
        int j = 0;
        for(int i=0;i<n;i++){
            j ^= (start + 2*i);
        }
        return j;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}