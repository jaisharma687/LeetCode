#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    unordered_map<char, string> keyboard;
    void solve(vector<string>& res, string temp, string d, int idx) {
        if (idx == d.size()) {
            res.push_back(temp);
            return;
        }
        string t = keyboard[d[idx]];
        int n = t.size();
        for (int i = 0; i < n; i++) {
            solve(res, temp + t[i], d, idx + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        keyboard['2'] = "abc";
        keyboard['3'] = "def";
        keyboard['4'] = "ghi";
        keyboard['5'] = "jkl";
        keyboard['6'] = "mno";
        keyboard['7'] = "pqrs";
        keyboard['8'] = "tuv";
        keyboard['9'] = "wxyz";
        vector<string> res;
        solve(res, "", digits, 0);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}