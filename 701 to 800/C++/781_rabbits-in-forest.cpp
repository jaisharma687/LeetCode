#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int res = 0;
            unordered_map<int,int> mpp;
            for(int i: answers){
                mpp[i]++;
            }
            for(auto& [key, freq]: mpp){
                int size = key + 1;
                int grps = ceil((double)freq/size);
                res += grps*size;
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}