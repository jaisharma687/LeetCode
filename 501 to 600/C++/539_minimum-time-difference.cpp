#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int toTime(string s){
        string h = s.substr(0,2);
        string m = s.substr(3,2);
        int time = 0;
        for(char x: h){
            time = time*10 + (int)(x-'0');
        }
        for(char x: m){
            time = time*10 + (int)(x-'0');
        }
        return time;
    }
    int calculateDifference(int a, int b){
        int dhr = abs(a/100-b/100);
        int dmin = (a%100-b%100);
        if(dhr>12){
            dhr = 24-dhr;
            return dhr*60 + dmin;
        }
        if(dhr==0) return abs(dmin);
        return dhr*60 - dmin;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(string s: timePoints){
            time.push_back(toTime(s));
        }
        sort(time.begin(),time.end());
        int d = calculateDifference(time[0],time[time.size()-1]);
        if(d==0) return d;
        for(int i=0;i<time.size()-1;i++){
            d = min(d, calculateDifference(time[i],time[i+1]));
        }
        return d;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();