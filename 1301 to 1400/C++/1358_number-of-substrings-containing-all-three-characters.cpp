#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int cnt = 0;
            int n = s.size();
            vector<int> count(3,0);
            int i = 0;
            for(int j=0;j<n;j++){
                count[s[j]-'a']++;
                while(count[0]>0 && count[1]>0 && count[2]>0){
                    cnt += n-j;
                    count[s[i]-'a']--;
                    i++;
                }
            }
            return cnt;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();