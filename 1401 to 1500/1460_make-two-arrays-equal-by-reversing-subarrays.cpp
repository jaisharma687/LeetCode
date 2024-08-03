#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        if(n!=m) return false;
        unordered_map<int,int> tar;
        for(auto x: target) tar[x]++;
        unordered_map<int,int> a;
        for(auto x: arr) a[x]++;
        return tar==a;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}