#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     long long putMarbles(vector<int>& weights, int k) {
//         priority_queue<int> maxHeap;
//         priority_queue<int,vector<int>,greater<>> minHeap;
//         int n = weights.size();
//         for(int i=0;i<n-1;i++){
//             int val = weights[i]+weights[i+1];
//             maxHeap.push(val);
//             minHeap.push(val);
//         }
//         long long mx = 0, mi = 0;
//         for(int i=0;i<k-1;i++){
//             mx += maxHeap.top();
//             maxHeap.pop();
//             mi += minHeap.top();
//             minHeap.pop();
//         }
//         return mx - mi;
//     }
// };

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            if(k<2) return 0;
            int n = weights.size();
            vector<int> sumArr;
            for(int i=0;i<n-1;i++){
                sumArr.push_back(weights[i]+weights[i+1]);
            }
            sort(sumArr.begin(),sumArr.end());
            long long mi=accumulate(sumArr.begin(),sumArr.begin()+k-1,0LL);
            long long mx=accumulate(sumArr.end()-k+1,sumArr.end(),0LL);
            return mx - mi;
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