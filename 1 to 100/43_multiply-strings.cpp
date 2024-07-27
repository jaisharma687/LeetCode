#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> pdt(num1.size()+num2.size(),0);
        if(num1=="0"||num2=="0") return "0";
        for(int i=0;i<num1.size();i++){
            int x = num1[num1.size() - i -1]-'0';
            for(int j=0;j<num2.size();j++){
                int y = num2[num2.size() - j -1]-'0';
                int p = x*y;
                int sum = p + pdt[i+j];
                pdt[i+j] = sum%10;
                pdt[i+j+1] += sum/10;
            }
        }
        string res;
        for(int i=num1.size()+num2.size()-1;i>=0;i--)
            if(!res.empty() || pdt[i] != 0) res.push_back(pdt[i]+'0');
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}