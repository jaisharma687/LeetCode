#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt = 0;
            for(int i=low;i<=high;i++){
                int n = log10(i)+1;
                if(n%2!=0) continue;
                int s = 0;
                int p = n/2;
                int j = i;
                while(p){
                    s+=j%10;
                    j/=10;
                    p--;
                }
                p = n/2;
                while(p){
                    s-=j%10;
                    j/=10;
                    p--;
                }
                if(s==0) cnt++;
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}