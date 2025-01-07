#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            string word = words[i];
            int l = word.size()-1;
            if((word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u') &&
            (word[l]=='a'||word[l]=='e'||word[l]=='i'||word[l]=='o'||word[l]=='u')){
                prefix[i+1] = prefix[i]+1;
            }
            else{
                prefix[i+1] = prefix[i];
            }
        }
        vector<int> res;
        for(auto&query:queries){
            res.push_back(prefix[query[1]+1]-prefix[query[0]]);
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