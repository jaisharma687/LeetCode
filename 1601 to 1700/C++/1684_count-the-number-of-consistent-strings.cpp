#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> word;
        for(char x:allowed) word.insert(x);
        int count = 0;
        for(string w:words){
            bool consistent = true;
            for(char x: w){
                if(find(word.begin(),word.end(),x)==word.end()){
                    consistent = false;
                    break;
                }
            }
            if(consistent) count++;
        }
        return count;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}