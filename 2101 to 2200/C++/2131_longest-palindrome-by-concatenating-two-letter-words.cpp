#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for(string word: words) mpp[word]++;
        int count = 0;
        int palWord = 0;
        for(auto& [word,freq]: mpp){
            string rev = word;
            reverse(rev.begin(),rev.end());
            if(rev==word){
                count += (freq/2)*4;
                if(freq%2==1) palWord = 1;
            }
            else if(word < rev && mpp.find(rev)!=mpp.end()){
                count += min(freq, mpp[rev]) * 4;
            }
        }
        return count + palWord * 2;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}