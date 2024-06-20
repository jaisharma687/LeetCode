#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxlen = 0;
        int start = 0;
        for(int i=0; i<s.length();i++){
            if(charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start ){
                start = charIndexMap[s[i]]+ 1;
            }
            charIndexMap[s[i]] = i;
            maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}