#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int passThePillow(int n, int time) {
        n--;//Suppose if there are 4 persons, the number of passes is 3 at a time., so for n person, there will be n-1 passes
        int t = time/n;
        if(t%2){
            return n - time%n + 1;
        }
        else{
            return time%n + 1;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}