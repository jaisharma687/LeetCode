#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool isPalindrome(int x) {
            int p = x;
            long pal = 0;
            while(p>0){
                pal = pal*10 + p%10;
                p/=10;
            }
            return pal==x;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}