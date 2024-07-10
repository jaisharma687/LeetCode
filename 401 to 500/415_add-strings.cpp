#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string out = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        int sum = 0;
        int rem = 0;
        while(i >= 0 && j >= 0){
            sum = (int)(num1[i]-'0') + (int)(num2[j]-'0') + carry;
            carry = sum / 10;
            rem = sum % 10;
            out = (char)(rem + '0') + out;
            i--,j--;
        }
        while(i >= 0){
            sum = (int)(num1[i]-'0') + carry;
            carry = sum / 10;
            rem = sum % 10;
            out = (char)(rem + '0') + out;
            i--;
        }
        while(j >= 0){
            sum = (int)(num2[j]-'0') + carry;
            carry = sum / 10;
            rem = sum % 10;
            out = (char)(rem + '0') + out;
            j--;
        }
        if(carry) out = (char)(carry + '0') + out;
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}