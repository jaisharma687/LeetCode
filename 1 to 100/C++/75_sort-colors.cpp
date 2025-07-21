#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]>nums[j]){
//                     int temp = nums[i];
//                     nums[i] = nums[j];
//                     nums[j] = temp; 
//                 }
//             }
//         }
//     }
// };

// Three Pointers problem or Dutch National flag algorithm
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low=0;
            int mid=0;
            int high=n-1;
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[mid],nums[low]);
                    low++;
                    mid++;
                }
                else if(nums[mid]==1){
                    mid++;
                }
                else{
                    swap(nums[mid],nums[high]);
                    high--;
                }
            }
        }
    };


class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i: nums){
            pq.push(i);
        }
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            nums[i] = pq.top();
            pq.pop();
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}