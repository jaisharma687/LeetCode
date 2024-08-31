#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

//brute force
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = INT_MIN;
        int n = s.size();
        int maxlen = 0;
        for(int l=0;l<n;l++){
            unordered_map<char,int> m;
            int maxfreq = 0;
            for(int r=l;r<n;r++){
                m[s[r]]++;
                maxfreq = max(maxfreq,m[s[r]]);
                int changes = r - l +1 - maxfreq;
                if(changes<=k) maxlen = max(maxlen,r-l+1);
                else break;
            }
        }
        return maxlen;
    }
};

//sliding window or two pointer
/*https://www.youtube.com/watch?v=_eNhaDCr6P0*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l=0,r=0;
        unordered_map<char,int> m;
        int maxfreq = 0;
        while(r<n){
            m[s[r]]++;
            maxfreq = max(maxfreq,m[s[r]]);
            while(r - l + 1 - maxfreq > k){
                m[s[l]]--;
                l++;
                maxfreq = 0;
                for(auto x:m) maxfreq = max(maxfreq,x.second);
            }
            if(r - l + 1 - maxfreq <= k) maxlen = max(maxlen,r - l + 1);
            r++;
        }
        return maxlen;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}