#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     string rle(string s){
//         int cnt = 1;
//         char prev = s[0];
//         int n = s.size();
//         string res = "";
//         for(int i=1;i<n;i++){
//             if(prev==s[i]){
//                 cnt++;
//             }else{
//                 res = res + to_string(cnt) + prev;
//                 prev = s[i];
//                 cnt = 1;
//             }
//         }
//         res = res + to_string(cnt) + prev;
//         return res;
//     }
//     string countAndSay(int n) {
//         string s = "1";
//         for(int i=1;i<n;i++){
//             s = rle(s);
//         }
//         return s;
//     }
// };

class Solution {
    public:
        string countAndSay(int n) {
            if(n==1){
                return "1";
            }
            string s = countAndSay(n-1);
            string res = "";
            int i = 0;
            while(i< s.size()){
                int cnt = 1;
                while(i+1< s.size() && s[i]==s[i+1]){
                    cnt++;
                    i++;
                }
                res += to_string(cnt) + s[i];
                i++;
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}