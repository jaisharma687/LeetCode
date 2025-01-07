#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     bool subsequence(string str1, string str2){
//         int i = 0;
//         for(char x: str1){
//             if(x==str2[i]){
//                 i++;
//             }
//         }
//         return i==str2.size();
//     }
//     bool solve(string str1, string str2, int i){
//         if(subsequence(str1,str2)){
//             return true;
//         }
//         if(i==str1.size()) return false;
//         string mod = str1;
//         mod[i] = ((((int)((char)(mod[i])-'a')+1)%26)+'a');
//         // cout<< str1 << " " << mod << " " << i << endl;
//         return solve(str1,str2,i+1) || solve(mod,str2,i+1);
//     }
//     bool canMakeSubsequence(string str1, string str2) {
//         return solve(str1,str2,0);
//     }
// };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int tarIdx = 0;
        int n = str2.size();
        for(char x: str1){
            if(tarIdx<n && (str2[tarIdx]-x+26)%26 <= 1){
                tarIdx++;
            }
        }
        return n==tarIdx;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();