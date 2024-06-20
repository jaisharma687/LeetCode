#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() == t.length()){
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            for(int i=0;i<s.length();i++){
                if(s[i] != t[i]){
                    return false;
                }
            }
            return true;
        }else return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}