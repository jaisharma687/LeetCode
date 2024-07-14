#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/*
https://www.youtube.com/watch?v=ld_W5tvJJsk
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        vector<map<string,int>> s(1);
        int n = formula.length();
        int i = 0;
        while(i<n){
            if(formula[i] == '('){
                s.push_back(map<string,int>());
                i++;
            }
            else if(formula[i] == ')'){
                map<string,int> current = s.back();
                s.pop_back();
                i++;
                int iStart = i;
                while(i<n && isdigit(formula[i]))
                    i++;
                int multiplier = (iStart == i)? 1 : stoi(formula.substr(iStart,i-iStart));
                for(auto x: current) s.back()[x.first] += x.second * multiplier;
            }
            else{
                int iStart = i++;
                while(i<n && islower(formula[i])) i++;
                string atom = formula.substr(iStart,i-iStart);
                iStart = i;
                while(i<n && isdigit(formula[i])) i++;
                int count = (iStart == i)? 1 : stoi(formula.substr(iStart,i-iStart));
                s.back()[atom] += count;
            }
        }
        string ans = "";
        map<string,int> counter = s.back();
        s.pop_back();
        for(auto x: counter){
            ans += x.first;
            if(x.second > 1) ans += to_string(x.second);
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}