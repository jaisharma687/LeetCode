#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// TLE Solution
// class Solution {
//     private:
//         static const long long mod = 1e9 + 7;
//     public:
//         int multiplier(long long base, long long expo){
//             long long res = 1;
//             while(expo>0){
//                 res = (res * base)%mod;
//                 expo--;
//             }
//             return (int)res;
//         }
//         int countGoodNumbers(long long n) {
//             long long even = (n + 1) / 2;
//             long long odd = n / 2;
//             return (int)((long long)multiplier((long long)5, even) * (long long)multiplier((long long)4, odd)%mod);
//         }
//     };

// Optimized Solution
class Solution {
    private:
        static const long long mod = 1e9 + 7;
    public:
        int multiplier(long long base, long long expo){
            long long res = 1;
            while(expo>0){
                if(expo%2==0){
                    base = (base*base)%mod;
                    expo /= 2;
                }
                else{
                    res = (res * base)%mod;
                    expo--;
                }
            }
            return (int)res;
        }
        int countGoodNumbers(long long n) {
            long long even = (n + 1) / 2;
            long long odd = n / 2;
            cout<<multiplier((long long)2, 10);
            return (int)((long long)multiplier((long long)5, even) * (long long)multiplier((long long)4, odd)%mod);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}