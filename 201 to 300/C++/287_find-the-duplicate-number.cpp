#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];//fast
        int tortoise = nums[0];//slow
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare != tortoise);

        tortoise = nums[0];//slow
        while(hare != tortoise){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}