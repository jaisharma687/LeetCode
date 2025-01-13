#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPrefixSuffix(string& str1, string& str2){
        int n = str2.size();
        int m = str1.size();
        if(m>n) return false;
        for(int i=0;i<m;i++){
            if(str1[i]!=str2[i]){
                return false;
            }
        }
        int r = m-1;
        for(int i=n-1;i>=n-m;i--){
            if(str1[r]!=str2[i]){
                return false;
            }
            r--;
        }
        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixSuffix(words[i],words[j])){
                    res++;
                }
            }
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