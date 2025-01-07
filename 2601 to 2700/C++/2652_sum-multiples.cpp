#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int sumOfMultiples(int n) {
        int s = 0;
        for(int i=0;i<=n;i++){
            if(i%3 == 0 || i%5==0 || i%7==0)s += i;
        }
        return s;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}