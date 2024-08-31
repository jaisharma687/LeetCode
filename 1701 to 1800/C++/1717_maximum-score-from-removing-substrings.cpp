#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int max = 0;
        char first = (x<y)?'b':'a';
        char second = (x<y)?'a':'b';
        int mv = (x<y)?y:x;
        int lv = (x<y)?x:y;
        int i = 0;
        while(s.size()>1 && i<s.size()-1){
            if(s[i] == first && s[i+1] == second){
                max += mv;
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                if(i!=0) i--;
            }else i++;
        }
        i=0;
        while(s.size()>1 && i<s.size()-1){
            if(s[i] == second && s[i+1] == first){
                max += lv;
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                if(i!=0) i--;
            }else i++;
        }
        return max;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}