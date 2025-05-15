#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long s1=0, s2=0, z1=0, z2=0;
            for(int x: nums1){
                if(x==0) z1++,s1++;
                else s1+=x;
            }
            for(int x: nums2){
                if(x==0) z2++, s2++;
                else s2+=x;
            }
            if((z1==0 && s2>s1)||(z2==0 && s1>s2)) return -1;
            return max(s1,s2);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}