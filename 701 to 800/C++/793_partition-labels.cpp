#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         vector<int> last(26,-1);
//         int n = s.size();
//         for(int i=0;i<n;i++){
//             int idx = s[i]-'a';
//             last[idx] = i;
//         }
//         int i = 0;
//         vector<int> res;
//         while(i<n){
//             int end = last[s[i]-'a'];
//             int j = i+1;
//             while(j<end){
//                 if(last[s[j]-'a']>end){
//                     end = last[s[j]-'a'];
//                 }
//                 j++;
//             }
//             res.push_back(end-i+1);
//             i = end+1;
//         }
//         return res;
//     }
// };

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> last(26,-1);
            int n = s.size();
            for(int i=0;i<n;i++){
                int idx = s[i]-'a';
                last[idx] = i;
            }
            int i = 0;
            int start = 0;
            int end=0;
            vector<int> res;
            while(i<n){
                end = max(end,last[s[i]-'a']);
                if(i==end){
                    res.push_back(end-start+1);
                    start = end+1;
                }
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

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();