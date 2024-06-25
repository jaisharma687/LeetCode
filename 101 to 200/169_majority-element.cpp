#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(count.find(nums[i]) == count.end()){
                count.insert(make_pair(nums[i],1));
            }else count[nums[i]]++;
        }
        for(auto i=count.begin();i!=count.end();i++){
            if(i->second > n/2){
                return i->first;
            }
        }
        return 0;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}