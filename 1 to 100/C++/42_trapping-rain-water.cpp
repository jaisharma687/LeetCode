#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// prefix and suffix soultion
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];
        for(int i=1;i<n;i++) prefix[i] = max(prefix[i-1],height[i]);
        for(int i=n-2;i>=0;i--)suffix[i] = max(suffix[i+1],height[i]);
        int water = 0;
        for(int i=0;i<n;i++) water += min(prefix[i],suffix[i]) - height[i];
        return water;
    }
};

//two pointer solution
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int biggestl = 0;
        int biggestr = 0;
        int res = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>biggestl) biggestl = height[l];
                else res += biggestl - height[l];
                l++;
            }
            else{
                if(height[r]>biggestr) biggestr = height[r];
                else res += biggestr - height[r];
                r--;
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