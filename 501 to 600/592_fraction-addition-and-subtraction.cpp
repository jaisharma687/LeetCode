#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string toString(int x){
        if(x==0) return "0";
        string out = "";
        while(x>0){
            out = (char)(x%10 + '0') + out;
            x/=10;
        }
        return out;
    }
    string fractionAddition(string expression) {
        vector<pair<int,int>> res;
        //0-plus, 1-minus
        int i=0;
        while(i<expression.size()){
            int sign=1;
            if(expression[i]=='-') sign = -1, i++;
            else if(expression[i]=='+') i++;
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num*=sign;
            i++;
            int deno = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                deno = deno * 10 + (expression[i] - '0');
                i++;
            }
            res.push_back({num, deno});
        }
        int num = 0; int deno = 1;
        for(auto x:res){
            int n = x.first;
            int d = x.second;
            num = num * d + deno * n;
            deno = d * deno;
            int gcd = std::gcd(num,deno);
            num /= gcd;
            deno /= gcd;
        }
        string s = "";
        if(num<0) s = "-";
        return s + toString(abs(num)) + '/' + toString(deno);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}