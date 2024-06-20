#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int binLen(int n){
        int l = 0;
        while(n != 0){
            l++;
            n /= 2;
        }
        return l;
    }

    int findKOr(vector<int>& nums, int k) {
        int max_ele = nums[0];

        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        
        int m = binLen(max_ele);
        
        int rows = nums.size();
        
        vector<vector<int>> map(rows,vector<int>(m,0));
        
        for(int i=0;i<rows;i++){
            int p = nums[i];
            int j = 0;
            while(p!=0){
                int rem = p%2;
                map[i][j] = rem;
                j++;
                p /= 2;
            }
        }
        
        vector<int> kor(m,0);
        for(int i=0;i<m;i++){
            int s = 0;
            for(int j=0;j<rows;j++){
                s += map[j][i];
            }
            if(s>=k){
                kor[i] = 1;
            }
        }

        int result = 0;
        for (int i = m-1; i >=0 ; i--) {
            result = result * 2 + kor[i];
        }

        return result;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}