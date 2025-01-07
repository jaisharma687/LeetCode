#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto x:nums){
            count[x]++;
        }
        int res=0;
        for(auto i=count.begin();i!=count.end();i++){
            if(i->second ==2){
                res ^= i->first;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}