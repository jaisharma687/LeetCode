#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vec(arr.begin(),arr.end());
        sort(vec.begin(),vec.end());
        unordered_map<int,int> m;
        unordered_set<int> visited;
        int rank = 1;
        for(int i=0;i<arr.size();i++){
            if(visited.find(vec[i])==visited.end()){
                m[vec[i]] = rank;
                visited.insert(vec[i]);
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();