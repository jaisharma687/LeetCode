#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(slow!=fast);
        int p = nums[0];
        while(p!=slow){
            p = nums[p];
            slow = nums[slow];
        }
        return slow;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}