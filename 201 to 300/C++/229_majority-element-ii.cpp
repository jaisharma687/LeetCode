#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            if(count.find(nums[i]) == count.end()){
                count.insert(make_pair(nums[i],1));
            }else count[nums[i]]++;
        }
        for(auto i = count.begin(); i!= count.end();i++){
            if(i->second > n/3){
                output.push_back(i->first);
            }
        }
        return output;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}