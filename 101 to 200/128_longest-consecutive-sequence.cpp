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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}