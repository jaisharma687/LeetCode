#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=1;i<=n-2;i++){
            if(arr[i] - arr[i-1] != arr[i+1] - arr[i]){
                return false;
            }
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}