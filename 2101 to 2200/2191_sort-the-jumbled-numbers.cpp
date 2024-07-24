#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> m;
        for(auto x : nums){
            string n = "";
            int p = x;
            if(x==0){
                m.push_back({x,mapping[x]});
            }
            else{
                while(p>0){
                    int rem = p %10;
                    p /= 10;
                    n = (char)(mapping[rem] + '0') + n;
                }
                int num = 0;
                int i=0;
                while(i<n.size()){
                    num = num * 10 + (int)(n[i]-'0');
                    i++;
                }
                m.push_back({x,num});
            }
        }
        sort(m.begin(),m.end(),[](auto& a, auto& b){
            return a.second < b.second;
        });
        vector<int> res;
        for(auto x:m){
            res.push_back(x.first);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}