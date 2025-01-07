#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long int p=0 ;
        for(int i=1;p<num;i+=2){
            p += i;
        }
        return (p==num)?true:false;
        
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}