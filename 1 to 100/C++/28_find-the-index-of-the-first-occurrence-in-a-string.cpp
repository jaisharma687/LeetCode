#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if(found == string::npos){
            return -1;
        }else return found;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}