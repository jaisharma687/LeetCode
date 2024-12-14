#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        long long res = 0;
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        while(r<n){
            maxHeap.push({nums[r],r});
            minHeap.push({nums[r],r});
            while(abs(maxHeap.top().first-minHeap.top().first)>2){
                l++;
                while(!maxHeap.empty() && maxHeap.top().second<l){
                    maxHeap.pop();
                }
                while(!minHeap.empty() && minHeap.top().second<l){
                    minHeap.pop();
                }
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }
};

// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0;
//         int r = 0;
//         long long res = 0;
//         map<int,int> mp;
//         int mx,mi;
//         while(r<n){
//             mp[nums[r]]++;
//             while(abs(mp.rbegin()->first-mp.begin()->first)>2){
//                 mp[nums[l]]--;
//                 if(mp[nums[l]]==0){
//                     mp.erase(nums[l]);
//                 }
//                 l++;
//             }
//             res += r - l + 1;
//             r++;
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