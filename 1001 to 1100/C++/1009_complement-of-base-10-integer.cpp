#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        string bin = "";
        while(n>=1){
            int rem = n % 2;
            if(rem){
                bin = "0" + bin;
            }else bin = "1" + bin;
            n /= 2;
        }
        int p = 1;
        int num = 0;
        for(int i=bin.size()-1;i>=0;i--){
            if(bin[i]=='1'){
                num += p;
            }
            p *= 2;
        }
        return num;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}