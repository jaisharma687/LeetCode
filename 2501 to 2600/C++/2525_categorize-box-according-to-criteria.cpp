#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long int vol = (long long int)length*width*height;
        bool bulk = false;
        bool heav = false;
        if(length >= pow(10,4) || width >= pow(10,4) || height >= pow(10,4) || vol >= pow(10,9)){
            bulk = true;
        }
        if(mass >= 100){
            heav = true;
        }
        if(bulk && heav){
            return "Both";
        }else if(!bulk && heav){
            return "Heavy";
        }else if(bulk && !heav){
            return "Bulky";
        }else return "Neither";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}