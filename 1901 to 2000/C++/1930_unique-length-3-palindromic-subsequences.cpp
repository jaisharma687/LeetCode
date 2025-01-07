#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         int res = 0;
//         unordered_set<char> letters;
//         for(char x: s){
//             letters.insert(x);
//         }
//         for(char letter: letters){
//             int left = -1;
//             int right = -1;
//             for(int i=0;i<s.size();i++){
//                 if(s[i]==letter){
//                     if(left==-1) left = i;
//                     right = i;
//                 }
//             }
//             unordered_set<char> visited;
//             for(int i=left+1;i<=right-1;i++){
//                 visited.insert(s[i]);
//             }
//             res += visited.size();
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        vector<pair<int,int>> letters(26,{-1,-1});
        for(int i=0;i<s.size();i++){
            int idx = (int)(s[i]-'a');
            if(letters[idx].first==-1){
                letters[idx].first = i;
            }
            letters[idx].second = i;
        }
        for(auto x: letters){
            int left = x.first;
            int right = x.second;
            unordered_set<char> visited;
            for(int i=left+1;i<=right-1;i++){
                visited.insert(s[i]);
            }
            res += visited.size();
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