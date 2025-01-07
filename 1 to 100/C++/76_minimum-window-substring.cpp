#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> tmap;
        for(char x:t) tmap[x]++;
        int count=tmap.size(),right=0,left=0,minlen=INT_MAX,minstart = 0;
        while(right<n){
            if(tmap.find(s[right])!=tmap.end()){
                tmap[s[right]]--;
                if(tmap[s[right]]==0) count--;
            }
            while(count==0){
                if(right-left+1<minlen){
                    minlen = right-left+1;
                    minstart = left;
                }
                if(tmap.find(s[left])!=tmap.end()){
                    tmap[s[left]]++;
                    if (tmap[s[left]] > 0) {
                        count++;
                    }
                }
                left++;
            }
            right++;
        }
        return minlen==INT_MAX ? "":s.substr(minstart,minlen);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}