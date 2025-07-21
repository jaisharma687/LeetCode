#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;
        for(int i=1;i<=n;i++){
            if(i%m) num1+=i;
            else num2+=i;
        }
        return num1-num2;
    }
};

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n*(n+1) / 2;
        int divSum = 0;
        for(int i=1;i<=n;i++){
            if(i%m==0){
                divSum += i;
            }
        }
        return totalSum - 2 * divSum;
    }
};

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n*(n+1) / 2;
        int q = n/m; // no of numbers divisible by m till n
        int divSum = (q*(q+1) / 2)*m; // sum of all the divisible numbers
        return totalSum - 2 * divSum;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}