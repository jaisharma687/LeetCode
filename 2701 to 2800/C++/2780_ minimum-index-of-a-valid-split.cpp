#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     long long majorityElement(vector<int>& nums, int start, int end){
//         int n = end - start + 1;
//         int count = 0;
//         long long element;
//         for(int i=start;i<=end;i++){
//             if(count==0){
//                 element = nums[i];
//                 count++;
//             }
//             else if(element==nums[i]) count ++;
//             else count--;
//         }
//         count = 0;
//         for(int i=start;i<=end;i++){
//             if(element==nums[i]) count ++;
//         }
//         if(count>n/2) return element;
//         return -1;
//     }
//     int minimumIndex(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int x = majorityElement(nums,0,i);
//             int y = majorityElement(nums,i+1,n-1);
//             if(x!=-1 && y!=-1 && x==y){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            // Find dominant Element no check as it is given that there exists a dominant element for the whole array
            int count = 0;
            long long element;
            for(int i=0;i<n;i++){
                if(count==0){
                    element = nums[i];
                    count++;
                }
                else if(element==nums[i]) count++;
                else count--;
            }
            // find the count of dominant element
            count = 0;
            for(int i=0;i<n;i++){
                if(element==nums[i]) count++;
            }
            // cout<<element<<" "<<count<<endl;
            // checking for each index is it dominant both sides
            int currCount = 0;
            for(int i=0;i<n;i++){
                if(element==nums[i]){
                    currCount++;
                }
                int remCount = count - currCount;
                cout<<currCount<<" "<<remCount<<endl;
                if(currCount > (i+1)/2 && remCount > (n-i-1)/2){
                    return i;
                }
            }
            return -1;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();