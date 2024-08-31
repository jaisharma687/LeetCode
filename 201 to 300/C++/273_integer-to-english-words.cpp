#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string generateHundred(unordered_map<int, string> d,int p){
        int ones = p%10; //7
        int tens = p%100; //47
        int hunds = (p%1000 - tens)/100; //6
        string out = "";
        if(hunds){
            out += d[hunds] + " " + d[100];
            if(tens){
                out += " ";
            }
        }
        if(tens){
            if(tens >= 20){
                out += d[tens - ones];
                if(ones){
                    out += " ";
                }
            }
            else{
                out += d[tens];
            }
        }
        if(ones && tens>20){
            out += d[ones];
        }
        return out;
    }
    string numberToWords(int num) {
        unordered_map<int, string> d{
            {0, "Zero"},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"},
            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
            {1000000000, "Billion"}
        };
        //num = 2147483647
        int hundred = num % 1000;// = 647
        int thousand = (num % 1000000 - hundred)/1000;// = 483
        int million = (num % 1000000000 - hundred - thousand * 1000)/1000000; // 147
        int billion = (num % 1000000000000 - hundred - thousand * 1000 - million * 1000000)/1000000000; // 2
        if(hundred == 0 && thousand ==0 && million == 0 && billion ==0) return d[0];
        string res = "";
        if(billion){
            res += generateHundred(d,billion);
            res += " " + d[1000000000];
            if(million || thousand || hundred) res += " ";
        }
        if(million){
            res += generateHundred(d,million);
            res += " " + d[1000000];
            if(thousand || hundred) res += " ";
        }
        if(thousand){
            res += generateHundred(d,thousand);
            res += " " + d[1000];
            if(hundred) res += " ";
        }
        if(hundred){
            res += generateHundred(d,hundred);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}