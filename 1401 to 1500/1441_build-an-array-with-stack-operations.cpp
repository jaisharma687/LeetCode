#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        vector<int> out;
        int j=0;
        for(int i=0;i<n;i++){
            res.push_back("Push");
            out.push_back(i+1);
            if(out == target) break;
            if(count(target.begin(),target.end(),i+1)==0){
                res.push_back("Pop");
                out.pop_back();
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