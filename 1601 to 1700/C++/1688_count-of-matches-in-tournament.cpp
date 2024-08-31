#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n!=1){
            if(n%2 == 0){
                matches += n/2;
                n /= 2;
            }
            else{
                matches += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return matches;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}