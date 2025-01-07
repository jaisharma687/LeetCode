#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string toHex(int num) {
        unordered_map<int, char> n = {
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'a'},
            {11, 'b'},
            {12, 'c'},
            {13, 'd'},
            {14, 'e'},
            {15, 'f'}
        };
        unordered_map<int,char> comp = {
            {0, 'f'},
            {1, 'e'},
            {2, 'd'},
            {3, 'c'},
            {4, 'b'},
            {5, 'a'},
            {6, '9'},
            {7, '8'},
            {8, '7'},
            {9, '6'},
            {10, '5'},
            {11, '4'},
            {12, '3'},
            {13, '2'},
            {14, '1'},
            {15, '0'}
        };
        string res = "";
        if(num==0) return "0";
        else if(num>0){
            while(num>0){
                int rem = num % 16;
                num /= 16;
                res = n[rem] + res;
            }
            return res;
        }else{
            num = abs(num) - 1;
            while(num>0){
                int rem = num % 16;
                num /= 16;
                res = comp[rem] + res;
            }
            while(res.length()!=8){
                res = "f" + res;
            }
            return res;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}