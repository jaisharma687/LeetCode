#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i] = 0;
            }else{
                digits[i] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}