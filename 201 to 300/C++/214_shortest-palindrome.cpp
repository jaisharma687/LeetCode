#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Brute Force Algorithm

// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string rev = s;
//         reverse(rev.begin(),rev.end());
//         int n = s.size();
//         int i = n;
//         string res;
//         while(true && i>0){
//             string a = s.substr(0,i);
//             string b = rev.substr(n-i,n);
//             if(a==b){
//                 res = rev.substr(0,i);
//                 break;
//             }
//             i--;
//         }
//         return res + p;
//     }
// };

// Using memcmp

// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string rev = s;
//         reverse(rev.begin(),rev.end());
//         int n = s.size();
//         int i = 0;
//         string res;
//         while(true && i<n){
//             if(memcmp(s.c_str()+0,rev.c_str()+i,n-i) == 0){
//                 res = rev.substr(0,i);
//                 break;
//             }
//             i++;
//         }
//         return res + s;
//     }
// };

// Using KMP

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        int n = s.size();
        vector<int> lps(2*n + 1);
        lps[0] = 0;
        string str = s + "#" + rev;
        int i = 1;
        int len = 0;
        while(i<=2*n){
            if(str[i] == str[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                if(len>0) len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return rev.substr(0,n-lps[2*n]) + s;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();