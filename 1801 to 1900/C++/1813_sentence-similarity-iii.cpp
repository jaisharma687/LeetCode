#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1,s2;
        stringstream ss1(sentence1);
        string str;
        while(getline(ss1,str,' ')){
            s1.push_back(str);
        }
        stringstream ss2(sentence2);
        while(getline(ss2,str,' ')){
            s2.push_back(str);
        }
        int l = 0;
        while(l<min(s1.size(),s2.size()) && s1[l].compare(s2[l])==0){
            l++;
        }
        if(l==min(s1.size(),s2.size())){
            return true;
        }
        int r1 = s1.size()-1;
        int r2 = s2.size()-1;
        while(l<=min(r1,r2)){
            if(s2[r2].compare(s1[r1])!=0){
                return false;
            }
            r1--;
            r2--;
        }
        return true;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();