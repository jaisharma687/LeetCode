#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0;
        int right = numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                return {left+1,right+1};
                break;
            }else if(numbers[left] + numbers[right]>target) right--;
            else left++;
        }
        return {};
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}