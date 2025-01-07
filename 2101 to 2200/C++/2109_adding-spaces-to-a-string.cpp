#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0;
        int n = spaces.size();
        for(int i=0;i<s.size();i++){
            if(j<n && i==spaces[j]){
                res += " ";
                j++;
            }
            res += s[i];
        }
        if(j<n){
            res += " ";
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();