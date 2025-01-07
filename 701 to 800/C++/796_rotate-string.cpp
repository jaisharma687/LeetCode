#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void rotateLeft(string &s){
        char first = s[0];
        s.erase(s.begin());
        s += first;
    }
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n!=goal.size()){
            return false;
        }
        string initial = goal;
        int i=0;
        while(i<n){
            if(goal==s){
                return true;
            }
            rotateLeft(goal);
            if(goal==initial){
                break;
            }
            i++;
        }
        return false;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();