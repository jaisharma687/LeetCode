#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// hashmap and sliding window
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

//set and sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> c;
        int l = 0;
        int res = 0;
        for(int r=0;r<n;r++){
            while(c.find(s[r])!=c.end()){
                c.erase(s[l]);
                l++;
            }
            c.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}