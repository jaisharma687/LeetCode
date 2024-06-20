#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        int l = (w1>=w2) ? w2 : w1;
        string p = "";
        int i;
        for(i=0;i<l;i++){
            p += word1[i];
            p += word2[i];
        }
        while(i<w1){
            p += word1[i];
            i++;
        }
        while(i<w2){
            p += word2[i];
            i++;
        }
        return p;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}