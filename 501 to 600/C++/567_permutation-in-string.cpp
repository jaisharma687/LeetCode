#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

//hashmap solution- not optimised
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        for(auto x:s1) m1[x]++;
        int l=0;
        int n1=s1.size();
        while(l+n1<=s2.size()){
            unordered_map<char,int> m2;
            for(int i=l;i<l+n1;i++) m2[s2[i]]++;
            if(m1==m2) return true;
            l++;
        }
        return false;
    }
};

//optimised sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26,0),m2(26,0);
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        for(int i=0;i<n1;i++) m1[s1[i]-'a']++,m2[s2[i]-'a']++;
        if(m1==m2) return true;
        for(int i=n1;i<n2;i++){
            m2[s2[i-n1]-'a']--;
            m2[s2[i]-'a']++;
            if(m1==m2) return true;
        }
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}