#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq;
        int n = nums1.size();
        int m = nums2.size();
        for(auto x:nums1) pq.push(x);
        for(auto x:nums2) pq.push(x);
        int s = n+m;
        double a;
        while(pq.size()>s/2){
            a = pq.top();
            pq.pop();
        }
        if(s%2==0){
            double b = pq.top();
            double out = (a+b)/2;
            return out;
        }
        return a;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}