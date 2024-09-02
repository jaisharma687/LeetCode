#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        for(int x:chalk) s+= x;
        long long rem = k%s;
        int n = chalk.size();
        int i = 0;
        while(i<n){
            rem-=chalk[i];
            if(rem<0) break;
            i++;
        }
        return i;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}