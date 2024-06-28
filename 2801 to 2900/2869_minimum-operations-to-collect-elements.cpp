#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool containsZero(vector<int> res,int k){
        for(int i=0;i<k;i++){
            if(res[i]==0){
                return true;
            }
        }
        return false;
    }
    int minOperations(vector<int>& nums, int k) {
        vector<int> res(k,0);
        int n = 0;
        while(containsZero(res,k)){
            int top = nums.back();
            nums.pop_back();
            if(top<=k) res[top-1]++;
            n++;
        }
        return n;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}