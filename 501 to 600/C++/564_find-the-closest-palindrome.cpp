#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPalindrome(const string &p) {
        int i = 0;
        int n = p.size();
        while (i < n / 2) {
            if (p[i] != p[n - i - 1]) return false;
            i++;
        }
        return true;
    }
    string smallerPalindrome(string p){
        int i = 0;
        int n = p.size();
        string s = "";
        if(n==1) {
            s += ((p[0]-'0')-1)+'0';
            return s;
        }
        if(isPalindrome(p)){
            i = n-1;
            while(i>0 && p[i]=='0')i--;
            if(i==0 && p[i]=='1'){
                return string(n-1,'0');
            }
            else{
                p[i] = ((p[i]-'0')-1)+'0';
                i++;
                while(i<n){
                    p[i] = '9';
                    i++;
                }
            }
        }
        i = 0;
        while(i<=n/2){
            if(p[i]!=p[n-i-1]){
                if(p[n-i-1] > p[i]) p[n-i-1] = p[i];
                else{
                    int j = n-i-2;
                    while(j>i && p[j] == '0') j--;
                    if (j == 0 && p[j] == '1') {
                        p = string(n - 1, '9');
                        return p;
                    }
                    p[j] = ((p[j]-'0')-1)+'0';
                    j++;
                    while(j!=n-i-1){
                        p[j] = '9';
                        j++;
                    }
                    p[n-i-1] = p[i];
                }
            }
            i++;
        }
        return p;
    }
    string biggerPalindrome(string p){
        int i = 0;
        int n = p.size();
        string s = "";
        if(n==1) {
            s += ((p[0]-'0')+1)+'0';
            return s;
        }
        if(isPalindrome(p)){
            i = n-1;
            while(i>0 && p[i]=='9')i--;
            if(i==0 && p[i]=='9'){
                return "1" + string(n-1,'0') + "1";
            }
            else{
                p[i] = ((p[i]-'0')+1)+'0';
                i++;
                while(i<n){
                    p[i] = '0';
                    i++;
                }
            }
        }
        i = 0;
        while(i<=n/2){
            if(p[i]!=p[n-i-1]){
                if(p[n-i-1] < p[i]) p[n-i-1] = p[i];
                else{
                    int j = n-i-2;
                    while(j>i && p[j] == '9') j--;
                    p[j] = ((p[j]-'0')+1)+'0';
                    j++;
                    while(j!=n-i-1){
                        p[j] = '0';
                        j++;
                    }
                    p[n-i-1] = p[i];
                }
            }
            i++;
        }
        return p;
    }
    string nearestPalindromic(string n) {
        string res = "";
        string s,b;
        if(n.size()==1){
            res += ((n[0]-'0')-1)+'0';
            return res;
        }
        s = smallerPalindrome(n);
        b = biggerPalindrome(n);
        long long num = stoll(n);
        long long smaller = stoll(s);
        long long bigger = stoll(b);
        if (num - smaller <= bigger - num) return s;
        else return b;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}