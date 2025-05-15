#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
            int cnt = 0;
            for(int i=0;i<n-2;i++){
                for(int k=i+2;k<n;k++){
                    if(abs(arr[i]-arr[k])<=c){
                        for(int j=i+1;j<k;j++){
                            if(abs(arr[i]-arr[j])<=a && abs(arr[k]-arr[j])<=b){
                                cnt++;
                            }
                        }
                    }
                }
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}