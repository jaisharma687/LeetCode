#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinks = 0;
        int exchange;
        while(numBottles>=numExchange){
            exchange = numBottles/numExchange;
            numBottles = exchange + numBottles % numExchange;
            drinks += exchange * numExchange;
        }
        return drinks += numBottles;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}