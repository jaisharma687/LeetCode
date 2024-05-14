#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int maximum69Number (int num) {
            string s = to_string(num);
            int max = num;
            for(int i=0;i<s.length();i++){
                if(s[i] == '9'){
                    s[i] = '6';
                }
                else{
                    s[i] = '9';
                }
                int n = stoi(s);
                if(n>max){
                    max = n;
                }
                if(s[i] == '9'){
                    s[i] = '6';
                }
                else{
                    s[i] = '9';
                }
            }
            return max;
        }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int num;
    cin>>num;
    Solution obj;
    cout<<obj.maximum69Number(num);
}