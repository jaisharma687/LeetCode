#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=0;i<n;i++){
            if((i+1)%15 == 0){
                res.push_back("FizzBuzz");
            }
            else if((i+1)%5==0){
                res.push_back("Buzz");
            }
            else if((i+1)%3==0){
                res.push_back("Fizz");
            }
            else{
                res.push_back(to_string(i+1));
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}