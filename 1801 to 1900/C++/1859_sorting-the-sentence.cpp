#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string sortSentence(string s) {
        int i = 0;
        int j = 0;
        vector<string> t(9,"");
        while(j < s.length()){
            if(s[j] == ' ') {
                int num = (int)(s[j-1] - '0');
                string sub = s.substr(i,j-i-1);
                t[num-1] = sub;
                i = j+1;
            }else if(j==s.length()-1){
                int num = (int)(s[j] - '0');
                string sub = s.substr(i,j-i);
                t[num-1] = sub;
                i = j+1;
            }
            j++;
        }
        string out = "";
        for(int k =0;k<t.size();k++){
            if(t[k]!=""){
                out += t[k];
                if(k != t.size()-1 && t[k+1]!="") out += " ";
            }
        }
        return out;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}