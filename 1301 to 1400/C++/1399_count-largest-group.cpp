#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     int countLargestGroup(int n) {
//         unordered_map<int,vector<int>> mp;
//         for(int i=1;i<=n;i++){
//             int s = 0;
//             int p = i;
//             while(p>0){
//                 s += p%10;
//                 p /= 10;
//             }
//             mp[s].push_back(i);
//         }
//         int mx = 0;
//         int cnt = 0;
//         for(auto x: mp){
//             int l = x.second.size();
//             if(l>mx){
//                 mx = l;
//                 cnt = 1;
//             }else if(l==mx){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int countLargestGroup(int n) {
//         unordered_map<int,int> mp;
//         for(int i=1;i<=n;i++){
//             int s = 0;
//             int p = i;
//             while(p>0){
//                 s += p%10;
//                 p /= 10;
//             }
//             mp[s]++;
//         }
//         int mx = 0;
//         int cnt = 0;
//         for(auto x: mp){
//             int l = x.second;
//             if(l>mx){
//                 mx = l;
//                 cnt = 1;
//             }else if(l==mx){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
    public:
        int countLargestGroup(int n) {
            vector<int> mp(37,0);
            for(int i=1;i<=n;i++){
                int s = 0;
                int p = i;
                while(p>0){
                    s += p%10;
                    p /= 10;
                }
                mp[s]++;
            }
            int mx = 0;
            int cnt = 0;
            for(auto x: mp){
                int l = x;
                if(l>mx){
                    mx = l;
                    cnt = 1;
                }else if(l==mx){
                    cnt++;
                }
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}