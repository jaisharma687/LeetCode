#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> visited;
        for(int x: arr){
            if(visited.count(2*x) || (x%2==0 && visited.count(x/2))){
                return true;
            }
            visited.insert(x);
        }
        return false;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();