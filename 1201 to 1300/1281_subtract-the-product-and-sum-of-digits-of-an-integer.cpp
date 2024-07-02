#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int pdt = 1;
        int sum = 0;
        while(n>0){
            int rem = n %10;
            pdt *= rem;
            sum += rem;
            n /= 10;
        }
        return pdt - sum;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}