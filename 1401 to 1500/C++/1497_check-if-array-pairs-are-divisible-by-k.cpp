#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            arr[i] = ((arr[i] % k) + k)%k;
            m[arr[i]]++;
        }
        unordered_set<int> visited;
        for(auto x: m){
            int rem = x.first;
            int count = x.second;
            if(rem == 0) {
                if(count % 2 != 0) return false;
            }
            else {
                int reqRem = k - rem;
                if(m[rem] != m[reqRem]) return false;
            }
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