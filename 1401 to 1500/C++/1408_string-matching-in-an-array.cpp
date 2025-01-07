#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            for(int j=0;j<words.size();j++){
                string w2 = words[j];
                if(i!=j && w2.size()>=word.size() && w2.find(word)!=string::npos){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();