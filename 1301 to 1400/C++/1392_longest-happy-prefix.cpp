#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     bool endsWith(string s, string x) {
//         int i = s.size() - 1;
//         int j = x.size() - 1;
//         while (j >= 0 && i >= 0 && s[i] == x[j]) {
//             i--;
//             j--;
//         }
//         return j == -1;
//     }

//     string longestPrefix(string s) {
//         for (int i = s.size()-1; i > 0; i--) {
//             string sub = s.substr(0, i);
//             // if (endsWith(s, sub)) {
//             //     return sub;
//             // }
//             // if(s.compare(s.size()-i,i,sub)==0){
//             //     return sub;
//             // }
//         }
//         return "";
//     }
// };

// Using KMP
class Solution {
    public:
        string longestPrefix(string s) {
            int n = s.size();
            vector<int> lps(n,0);
            int prefix = 0;
            int suffix = 1;
            while(suffix<n){
                if(s[prefix]==s[suffix]){
                    lps[suffix] = prefix +1;
                    prefix++;
                    suffix++;
                }
                else{
                    if(prefix==0){
                        lps[suffix] = 0;
                        suffix++;
                    }else{
                        prefix = lps[prefix-1];
                    }
                }
            }
            return s.substr(0,prefix);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();