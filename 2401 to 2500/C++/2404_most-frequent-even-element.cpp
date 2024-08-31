#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> output;
        unordered_map<int, int> count; 
        int max = 0;
        for(auto i:nums){
            if(i%2==0) {
                count[i]++;
                if(max < count[i]){
                    max = count[i];
                }    
            }
            
        }
        for(auto i=count.begin();i!=count.end();i++){
            if(i->second == max){
                output.push_back(i->first);
            }
        }
        sort(output.begin(),output.end());
        if(output.size()){
            return output[0];
        }else return -1;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}