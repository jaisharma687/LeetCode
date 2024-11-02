#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string makeFancyString(string s) {
        string out = "";
        int m = 1;
        char prev = ' ';
        for(char x: s){
            if(prev!= x){
                m = 1;
                out += x;
            }
            else{
                if(m<2){
                    out += x;
                    m++;
                }
                else{
                    m++;
                }
            }
            prev = x;
        }
        return out;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();