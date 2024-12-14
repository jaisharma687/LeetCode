#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // int n = gifts.size();
        // int i=0;
        // while(i<k){
        //     auto pos = max_element(gifts.begin(), gifts.end());
        //     *pos = floor(sqrt(*pos));
        //     i++;
        // }
        // long long res = 0;
        // for(long long x: gifts){
        //     res += x;
        // }
        // return res;
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while(k>0){
            int ele = pq.top();
            pq.pop();
            pq.push(sqrt(ele));
            k--;
        }
        long long res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};

// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         int n = gifts.size();
//         int i=0;
//         while(i<k){
//             auto pos = max_element(gifts.begin(), gifts.end());
//             *pos = floor(sqrt(*pos));
//             i++;
//         }
//         long long res = 0;
//         for(long long x: gifts){
//             res += x;
//         }
//         return res;
//     }
// };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();