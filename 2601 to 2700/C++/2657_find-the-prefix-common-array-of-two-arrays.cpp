#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> map;
        int n = A.size();
        int count = 0;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            map[A[i]]++;
            map[B[i]]++;
            if(map[A[i]]==2) count++;
            if(A[i]!=B[i] && map[B[i]]==2) count++;
            res[i] = count;
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();