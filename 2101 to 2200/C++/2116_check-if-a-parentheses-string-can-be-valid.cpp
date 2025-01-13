#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2==1) return false;
        stack<int> open;
        stack<int> openClose;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(locked[i]=='1'){
                    open.push(i);
                }else{
                    openClose.push(i);
                }
            }else{
                if(locked[i]=='1'){
                    if(!open.empty()){
                        open.pop();
                    }else{
                        if(!openClose.empty()){
                            openClose.pop();
                        }else{
                            return false;
                        }
                    }
                }else{
                    openClose.push(i);
                }
            }
        }
        while(!open.empty()){
            if(!openClose.empty() && open.top()<openClose.top()){
                open.pop();
                openClose.pop();
            }else{
                return false;
            }
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