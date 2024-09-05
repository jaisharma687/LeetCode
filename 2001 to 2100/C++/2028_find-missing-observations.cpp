#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    /*bool findNrolls(int n, int ind, vector<int>&res, int target){
        if(ind==n){
            if(target==0){
                return true;
            }
            return false;
        }
        for(int i=1;i<=6;i++){
            if(target-i==0 && ind<n-1) break;
            else if(target-i>=0){
                res[ind] = i;
                if(findNrolls(n,ind+1,res,target-i)){
                    return true;
                }
            }
        }
        return false;
    }*/
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sm = 0;
        for(auto x : rolls) sm += x;
        int sn = mean*(n+m) - sm;
        if(sn > 6*n || sn < n) return {};
        vector<int> res(n,1);
        /*findNrolls(n,0,res,sn);
        return res;*/
        int cur = n;
        int i = 0;
        while(sn-cur+1>6){
            res[i] = 6;
            i++;
            cur += 5;
        }
        res[i] = sn - cur + 1 ;
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}