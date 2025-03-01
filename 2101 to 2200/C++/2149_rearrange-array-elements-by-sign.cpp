#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        // Brute force
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int> pos;
            vector<int> neg;
            for(int x: nums){
                if(x<0){
                    neg.push_back(x);
                }else{
                    pos.push_back(x);
                }
            }
            int i=0;
            int n = nums.size();
            while(i<n/2){
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
                i++;
            }
            return nums;
        }

        // Single Pass
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n);
            int i=0;
            int j=1;
            for(int x: nums){
                if(x<0){
                    res[j]= x;
                    j+=2;
                }else{
                    res[i]=x;
                    i+=2;
                }
            }
            return res;
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();