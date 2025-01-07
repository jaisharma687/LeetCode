#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=1;i<arr.size()-1;i++)
            if(arr[i-1]%2 && arr[i]%2 && arr[i+1]%2) return true;
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}