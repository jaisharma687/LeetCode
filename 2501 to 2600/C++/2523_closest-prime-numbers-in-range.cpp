#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Soultion 1: Gets the work done
// class Solution {
// public:
//     bool isPrime(int n){
//         if(n%2==0 || n%3==0){
//             return true;
//         }
//         for(int i=5;i*i<=n;i+=2){
//             if(n%i==0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     vector<int> closestPrimes(int left, int right) {
//         int a,b;
//         bool foundA=false;
//         bool foundB=false;
//         int diff = -1;
//         int prev = -1;
//         for(int i=left;i<=right;i++){
//             if(i==1 || (i>2 && i%2==0) || (i>3 && i%3==0)){
//                 continue;
//             }
//             cout<<prev<<endl;
//             if(isPrime(i)){
//                 if(!foundA){
//                     a=i;
//                     foundA=true;
//                 }else if(!foundB){
//                     b=i;
//                     diff = b-a;
//                     foundB=true;
//                 }else{
//                     if((i-max(prev,b))<diff){
//                         diff = i-max(prev,b);
//                         a = max(prev,b);
//                         b = i;
//                     }
//                     prev = i;
//                 }
//                 if(diff==1){
//                     break;
//                 }
//                 if(left>=3 && diff==2){
//                     break;
//                 }
//             }
//         }
//         if(diff==-1){
//             return {-1,-1};
//         }
//         return {a,b};
//     }
// };

// Solution 2: More clean code
class Solution {
    public:
        bool isPrime(int n){
            if(n<=1) return false;
            if(n<=3)return true;
            if(n%2==0 || n%3==0) return false;
            for(int i=5;i*i<=n;i+=2){
                if(n%i==0) return false;
            }
            return true;
        }
        vector<int> closestPrimes(int left, int right) {
            int a=-1,b=-1;
            int diff = INT_MAX;
            int prev = -1;
            for(int i=left;i<=right;i++){
                if(isPrime(i)){
                    if(prev!=-1){
                        int d = i - prev;
                        if(d<diff){
                            a = prev;
                            b = i;
                            diff = d;
                        }
                    }
                    prev = i;
                    if(diff==1){
                        break;
                    }
                    if(left>2 && diff==2){
                        break;
                    }
                }
            }
            if(a==-1 && b==-1){
                return {-1,-1};
            }
            return {a,b};
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();