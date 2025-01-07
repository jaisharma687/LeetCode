#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
/*
In order to do this, first we can sort the elements and then either
1. Kill last 3 elements
2. Kill last 2 elements and first 1 element
3. Kill last 1 element and first 2 element
4. Kill first 3 elements
Here, killing would mean either changing it to new max_ele or new min_ele
*/
    int min(int a, int b){
        return (a>b)?b:a;
    }
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m1 = abs(nums[0]-nums[n-4]);//last 3
        int m2 = min(abs(nums[1]-nums[n-3]),m1);//last 2 and first
        int m3 = min(abs(nums[2]-nums[n-2]),m2);//last and first 2
        return min(abs(nums[3]-nums[n-1]),m3);//first 3
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}