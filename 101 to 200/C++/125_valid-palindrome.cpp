#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> p;
        for(auto x:s)
            if(isalnum(x)) p.emplace_back(tolower(x));
        vector<char> rev;
        for(int i=p.size()-1;i>=0;i--)
            rev.emplace_back(p[i]);
        return rev == p;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> p;
        for(char x: s){
            if((x>='A' && x<='Z')||(x>='a' && x<='z')||(x>='0' && x<='9')){
                p.push_back(tolower(x));
            }
        }
        int start = 0;
        int end = p.size()-1;
        while(start<end){
            if(p[start]!=p[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}