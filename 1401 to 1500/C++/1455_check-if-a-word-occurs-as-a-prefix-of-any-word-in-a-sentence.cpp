#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int r=0;
        int l=0;
        vector<string> words;
        for(char x: sentence){
            if(x==' '){
                words.push_back(sentence.substr(l,r-l));
                l = r+1;
                r = r+1;
            }
            else r++;
        }
        words.push_back(sentence.substr(l,r-l+1));
        int idx = 0;
        for(string word: words){
            // cout<<word<<endl;
            int c = 0;
            for(char x: searchWord){
                if(x==word[c]){
                    c++;
                }
                else break;
            }
            if(c==searchWord.size()){
                return idx+1;
            }
            idx++;
        }
        return -1;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();