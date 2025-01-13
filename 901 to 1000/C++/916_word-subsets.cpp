#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isUniversal(vector<int> max_freq, vector<int> temp){
        for(int i=0;i<26;i++){
            if(temp[i]<max_freq[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26,0);
        for(auto& word : words2){
            vector<int> temp(26,0);
            for(char& x: word){
                temp[x-'a']++;
            }
            for(int i=0;i<26;i++){
                max_freq[i] = max(max_freq[i],temp[i]);
            }
        }
        vector<string> res;
        for(auto& word: words1){
            vector<int> temp(26,0);
            for(char& x: word){
                temp[x-'a']++;
            }
            if(isUniversal(max_freq,temp)){
                res.push_back(word);
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