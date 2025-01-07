#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        for(int i=0, j=0;i<n || j<n ;i++,j++){
            while(i<n && start[i]=='_'){
                i++;
            }
            while(j<n && target[j]=='_'){
                j++;
            }
            char c = start[i];
            if(c != target[j]) return false;
            if(c == 'L' && j>i) return false;
            if(c == 'R' && i>j) return false; 
        }
        return true;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();