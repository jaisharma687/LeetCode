#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> backtrack(int left, int right, string exp){
        vector<int> res;
        for(int i=left;i<=right;i++){
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                vector<int> num1 = backtrack(left,i-1,exp);
                vector<int> num2 = backtrack(i+1,right,exp);
                for(int x: num1){
                    for(int y: num2){
                        if(exp[i] == '+') res.push_back(x+y);
                        else if(exp[i] == '-') res.push_back(x-y);
                        else if(exp[i] == '*') res.push_back(x*y);
                    }
                }
            }
        }
        if(res.size()==0) res.push_back(stoi(exp.substr(left,right-left+1)));
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return backtrack(0,expression.size()-1,expression);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();