#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> m;
        int p = 0;
        for(auto i:candyType){
            if(m[i]==0){
                m[i]++;
                p++;
            }
        }
        return (p > candyType.size()/2) ? candyType.size()/2 : p;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}