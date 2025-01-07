#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string compressedString(string word) {
        int m = 1;
        string out = "";
        char prev = ' ';
        for(char w:word){
            if(prev==w){
                m++;
            }
            else{
                while(m>0 && prev != ' '){
                    if(m<9){
                        out += to_string(m) + prev;
                    }else{
                        out += to_string(9) + prev;
                    }
                    m -= 9;
                }
                m=1;
            }
            prev = w;
        }
        while(m>0){
            if(m<9){
                out += to_string(m) + prev;
            }else{
                out += to_string(9) + prev;
            }
            m -= 9;
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