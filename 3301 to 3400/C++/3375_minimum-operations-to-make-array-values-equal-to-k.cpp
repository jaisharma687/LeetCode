#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<int> pq;
            for(int x: nums){
                pq.push(x);
                if(x<k) return -1;
            }
            int res = 0;
            while(!pq.empty()){
                int val = pq.top();
                if(val==k) break;
                while(!pq.empty() && pq.top()==val) pq.pop();
                res++;
            }
            return res;
        }
    };
    
    // class Solution {
    // public:
    //     int minOperations(vector<int>& nums, int k) {
    //         unordered_set<int> unique_elements;
    //         for(int x: nums){
    //             if(x<k) return -1;
    //             if(x>k) unique_elements.insert(x);
    //         }
    //         return unique_elements.size();
    //     }
    // };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}