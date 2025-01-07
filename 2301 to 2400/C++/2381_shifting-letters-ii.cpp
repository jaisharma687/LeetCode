#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> sh(n+1,0);
        for(auto& shift: shifts){
            int st = shift[0];
            int ed = shift[1];
            int dir = shift[2];
            if(dir){
                sh[st]++;
                sh[ed+1]--;
            }else{
                sh[st]--;
                sh[ed+1]++;
            }
        }
        vector<int> prefix(n+1,0);
        prefix[0]=sh[0];
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+sh[i];
        string res = "";
        for(int i=0;i<n;i++){
            int shift = prefix[i];
            while(shift>=26) shift-=26;
            while(shift<0) shift+=26;
            char t = (char)((((int)(s[i]-'a')+shift)%26)+'a');
            res += t;
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