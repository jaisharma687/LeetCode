#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Solution 1: Using map
// TC: O(n) SC: O(n)
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


// Solution 2: Using Boyer-Moore Voting Algorithm
// TC: O(n) SC: O(1)
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            int cnt1=0;
            int cnt2=0;
            int ele1=INT_MIN;
            int ele2=INT_MIN;
            for(int x: nums){
                if(cnt1==0 && x!=ele2){
                    cnt1++;
                    ele1=x;
                }
                else if(cnt2==0 && x!=ele1){
                    cnt2++;
                    ele2=x;
                }
                else if(x==ele1) cnt1++;
                else if(x==ele2) cnt2++;
                else{
                    cnt1--;
                    cnt2--;
                }
            }
            vector<int> ans;
            cnt1=0;
            cnt2=0;
            for(int x: nums){
                if(x==ele1) cnt1++;
                if(x==ele2) cnt2++;
            }
            if(cnt1>n/3) ans.push_back(ele1);
            if(cnt2>n/3) ans.push_back(ele2);
            return ans;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}