#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> past;
        sort(queries.begin(), queries.end());
        int cnt = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            while(j<q && queries[j][0] == i){
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i] -= past.size();

            while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i){
                past.push(maxHeap.top());
                maxHeap.pop();
                cnt++;
                nums[i]--;
            }

            if(nums[i]>0) return -1;

            while(!past.empty() && past.top()==i){
                past.pop();
            }
        }
        return q - cnt;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}