#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int res = -1;
        vector<int> out;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    out.push_back(nums1[i]);
                    nums1[i] = res--;
                    nums2[j] = res--;
                }
            }
        }
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}