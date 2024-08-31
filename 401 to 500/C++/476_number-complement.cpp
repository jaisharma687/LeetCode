#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int i = 0;
        while(num>0){
            int rem = num % 2;
            if(rem==0) res += pow(2,i);
            num /= 2;
            i++;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}