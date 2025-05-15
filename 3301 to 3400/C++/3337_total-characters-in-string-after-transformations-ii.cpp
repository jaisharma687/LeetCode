#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
private:
    static const int mod = 1e9 + 7;
public:
    vector<vector<long long>> matrixMult(vector<vector<long long>>& a, vector<vector<long long>>& b){
        vector<vector<long long>> res(26,vector<long long>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return res;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> m, int n){
        vector<vector<long long>> res(26,vector<long long>(26,0));
        for(int i=0;i<26;i++) res[i][i] = 1;
        while(n>0){
            if(n%2==1){
                res = matrixMult(res, m);
            }
            m = matrixMult(m,m);
            n /= 2;
        }
        return res;
    }

    vector<vector<long long>> transitionMatrix(vector<int>& nums){
        vector<vector<long long>> trans(26,vector<long long>(26,0));
        for(int i=0;i<26;i++){
            int n = nums[i];
            for(int j=1;j<=n;j++){
                trans[i][(j+i)%26]++;
            }
        }
        return trans;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> transition = transitionMatrix(nums);
        transition = matrixPow(transition, t);
        vector<long long> freq(26,0);
        for(char x: s) freq[x-'a']++;
        long long total = 0;
        for(int j = 0; j < 26; j++){
            for(int i = 0; i < 26; i++){
                total = (total + freq[j] * transition[j][i]) % mod;
            }
        }
        return total;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}