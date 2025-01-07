#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx = arrays[0][arrays[0].size()-1];
        int mi = arrays[0][0];
        int diff = 0;
        for(int i=1;i<arrays.size();i++){
            int n = arrays[i].size()-1;
            diff = (diff < abs(arrays[i][n]-mi))?abs(arrays[i][n]-mi):diff;
            diff = (diff < abs(arrays[i][0]-mx))?abs(arrays[i][0]-mx):diff;
            mi = (mi>arrays[i][0])?arrays[i][0]:mi;
            mx = (mx<arrays[i][n])?arrays[i][n]:mx;
        }
        return diff;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}