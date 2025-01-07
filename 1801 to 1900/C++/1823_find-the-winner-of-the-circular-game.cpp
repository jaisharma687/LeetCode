#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> stack;
        int i=1;
        while(i<=n) stack.push_back(i),i++;
        int start = 0;
        int next;
        while(stack.size()>1){
            next = (start+k-1)%stack.size();
            start = next;
            stack.erase(stack.begin()+next);
        }
        return stack[0];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}