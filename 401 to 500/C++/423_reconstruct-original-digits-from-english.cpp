#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> freq(26,0);
        for(char x: s) freq[x-'a']++;
        vector<int> cnt(10,0);

        cnt[0] = freq['z'-'a'];
        cnt[2] = freq['w'-'a'];
        cnt[4] = freq['u'-'a'];
        cnt[6] = freq['x'-'a'];
        cnt[8] = freq['g'-'a'];

        cnt[1]= freq['o'-'a']-cnt[0]-cnt[2]-cnt[4];
        cnt[3]= freq['h'-'a']-cnt[8];
        cnt[5]= freq['f'-'a']-cnt[4];
        cnt[7]= freq['s'-'a']-cnt[6];
        cnt[9]= freq['i'-'a']-cnt[5]-cnt[6]-cnt[8];
        
        string res = "";
        for(int i=0;i<10;i++){
            res += string(cnt[i],'0'+i);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}