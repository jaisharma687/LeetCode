#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findPos(vector<int>& d, int i){
        if(d[i] == 0){
            if(i<d.size()-1){
                return findPos(d,i+1);
            }else{
                return 2;
            }
        }else if(d[i] > 0){
            return 1;
        }else{
            return -1;
        }
    }
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        vector<int> d(nums.size()-1,0);
        for(int i=0;i<nums.size()-1;i++){
            d[i] = nums[i+1] - nums[i];
        }
        int pos = findPos(d,0);
        if(pos == 2){
            return true;
        }
        for(int i=1;i<nums.size()-1;i++){
            if((pos == 1 && d[i] < 0) || (pos == -1 && d[i] > 0))
                return false;
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}