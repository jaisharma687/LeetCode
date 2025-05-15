#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int lengthAfterTransformations(string s, int t) {
            static const int mod = 1e9 + 7;
            vector<int> freq(26,0);
            for(char x: s){
                freq[x-'a']++;
            }
            while(t--){
                vector<int> newFreq(26,0);
                for(int i=0;i<26;i++){
                    if(i==25){
                        newFreq[0] = (newFreq[0] + freq[i])%mod;
                        newFreq[1] = (newFreq[1] + freq[i])%mod;
                    }else{
                        newFreq[i+1] = (newFreq[i+1] + freq[i])%mod;
                    }
                }
                freq = newFreq;
            }
            int res = 0;
            for(int x: freq){
                res = (res + x)%mod;
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}