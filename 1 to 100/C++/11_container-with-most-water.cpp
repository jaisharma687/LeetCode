#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int min(int a, int b){
        return (a>b)?b:a;
    }
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int area = min(height[left],height[right])*(right-left);
            max = (area>max)?area:max;
            if(height[left]>height[right]) right--;
            else left++;
        }
        return max;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}