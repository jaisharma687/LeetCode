#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        int l = 0;
        int r = 0;
        int n = sentence.size();
        string word;
        while(r<n){
            if(sentence[r]!=' '){
                r++;
            }
            else{
                word = sentence.substr(l,r-l);
                words.push_back(word);
                r++;
                l = r;
            }
        }
        word = sentence.substr(l,r-l);
        words.push_back(word);
        n = words.size();
        for(int i=0;i<n-1;i++){
            int len = words[i].size();
            if(words[i][len-1]!=words[i+1][0]){
                return false;
            }
        }
        int len = words[n-1].size();
        if(words[n-1][len-1]!=words[0][0]){
            return false;
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