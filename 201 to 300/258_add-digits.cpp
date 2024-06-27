#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int p = num;
            num = 0;
            while(p>0){
                int rem = p%10;
                num += rem;
                p /= 10;
            }
        }
        return num;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}