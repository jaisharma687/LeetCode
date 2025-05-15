#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool checkIfPangram(string sentence) {
            vector<int> freq(26,0);
            for(char x: sentence){
                int idx = x-'a';
                freq[idx]++;
            }
            for(int x: freq){
                if(x<1) return false;
            }
            return true;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}