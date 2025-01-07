#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<pair<int,int>> st;
        int i = 0;
        while(i!=n){
            if(!st.empty()){
                auto tp = st.top();
                while(!st.empty() && tp.first>=prices[i]){
                    prices[tp.second] -= prices[i];
                    st.pop();
                    if(!st.empty()) tp = st.top();
                }
            }
            st.push({prices[i],i});
            i++;
        }
        return prices;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();