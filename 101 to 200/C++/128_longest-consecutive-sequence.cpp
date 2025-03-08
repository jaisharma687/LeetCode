#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n;
        for(int x:nums) n.insert(x);
        int l=0;
        unordered_set<int> visited;
        for(int x:nums){
            if(visited.find(x)!=visited.end()) continue;
            visited.insert(x);
            int s = 0;
            if(n.find(x-1)==n.end()){
                s++;
                while(n.find(x+1)!=n.end()){
                    x++;
                    s++;
                    visited.insert(x);
                }
            } 
            if(s>l) l=s;
        } 
        return l;
    }
};

// Solution 1: TC: O(nlogn + n) SC: O(1)

// int longestSuccessiveElements(vector<int>&a) {
//     // Write your code here.
//     sort(a.begin(),a.end());
//     int mx = INT_MIN;
//     int curr = 1;
//     int n = a.size();
//     for(int i=1;i<n;i++){
//         if(a[i]==a[i-1]) continue;
//         if(a[i]-a[i-1]==1){
//             curr++;
//         }else{
//             mx = max(mx,curr);
//             curr=1;
//         }
//     }
//     mx = max(mx,curr);
//     return mx;
// }

// Solution 2: TC: O(n + 2n) SC: O(n)
// O(N) for putting all the elements into the set data structure. 
// After that for every starting element, we are finding the 
// consecutive elements. Though we are using nested loops, 
// the set will be traversed at most twice in the worst case. 
// So, the time complexity is O(2*N) instead of O(N2).

int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    unordered_set<int> st;
    for(int x: a){
        st.insert(x);
    }
    int mx = INT_MIN;
    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int curr = 1;
            int x = it+1;
            while(st.find(x)!=st.end()){
                x++;
                curr++;
            }
            mx = max(mx,curr);
        }
    }
    return mx;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}