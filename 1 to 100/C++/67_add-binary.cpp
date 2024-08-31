#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int carry = 0;
    char addition(char a, char b){
        if(carry){
            if(a == '1' && b == '1')return '1';
            else if(a == '1' && b == '0')return '0';
            else if(a == '0' && b == '1')return '0';
            else{
                carry = 0;
                return '1';
            }
        }else{
            if(a == '1' && b == '1'){carry = 1; return '0';}
            else if(a == '1' && b == '0')return '1';
            else if(a == '0' && b == '1')return '1';
            else return '0';
        }
    }
    string addBinary(string a, string b) {
        int j = b.length()-1;
        int i = a.length()-1;
        string res = "";
        while(i >= 0 && j >= 0){
            res = addition(a[i],b[j]) + res;
            i--,j--;
        }
        while(i>=0){
            res = addition(a[i],'0') + res;
            i--;
        }
        while(j>=0){
            res = addition('0',b[j]) + res;
            j--;
        }
        return (carry)?'1'+res:res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}