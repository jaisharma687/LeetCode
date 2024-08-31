#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> f;
        for(auto x:arr) f[x]++;
        int i=0;
        for(auto x:arr){
            if(f[x] == 1) ++i;
            if(i==k) return x;
        }
        return "";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}