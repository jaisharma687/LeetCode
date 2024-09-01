#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int n = 0;
        string m = "";
        for(int i=0;i<4;i++){
            int t = min(num1%10,min(num2%10,num3%10));
            num1/=10;
            num2/=10;
            num3/=10;
            char temp = (char)(t-'0');
            m = temp + m;
        }
        int i=0;
        while(m[i]=='0' && i<4) i++;
        int res = 0;
        for(int j=i;j<4;j++){
            res = res*10 + (m[j]+'0');
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}