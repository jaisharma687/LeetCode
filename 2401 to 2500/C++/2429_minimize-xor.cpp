#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    pair<int,string> toBinaryString(int num){
        string res = "";
        int setBits = 0;
        while(num>0){
            char rem = (num%2)+'0';
            res = rem + res;
            if(num%2) setBits++;
            num/=2;
        }
        return {setBits,res};
    }
    int toInt(string s){
        int val = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') val += pow(2,n-i-1);
        }
        return val;
    }
    int minimizeXor(int num1, int num2) {
        if(num1==num2) return num1;
        pair<int,string> p1, p2;
        p1 = toBinaryString(num1);
        p2 = toBinaryString(num2);
        cout<<p1.second<<" "<<p2.second<<endl;
        if(p1.first == p2.first){
            return num1;
        }else if(p1.first > p2.first){
            int n = p1.second.size();
            string s = p1.second;
            int setBits = p2.first;
            string res = "";
            for(int i=0;i<n;i++){
                if(setBits>0 && s[i]=='1'){
                    setBits--;
                    res+="1";
                }else{
                    res+="0";
                }
            }
            return toInt(res);
        }else{
            int n = p1.second.size();
            string s = p1.second;
            int setBits = p1.first;
            string res = "";
            for(int i=n-1;i>=0;i--){
                if(setBits>0 && s[i]=='1'){
                    setBits--;
                    res="1"+res;
                }else{
                    res="0"+res;
                }
            }
            cout<<res<<" ";
            int m = p2.second.size();
            while(res.size()<max(m,n)){
                res = "0" + res;
            }
            cout<<res;
            int left = p2.first - p1.first;
            for(int i=max(m,n)-1;i>=0;i--){
                if(res[i]!='1'){
                    res[i]='1';
                    left--;
                    if(left==0) break;
                }
            }
            cout<<" "<<res;
            return toInt(res);
        }
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();