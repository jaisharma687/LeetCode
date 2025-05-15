#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     set<int> res;
//     void dfs(vector<int>& freq, int num){
//         if(num>999) return;
//         if(num>=100 && num<=999 && num%2==0){
//             res.insert(num);
//             return;
//         }
//         for(int i=0;i<10;i++){
//             if(num==0 && i==0) continue;
//             if(freq[i]>0){
//                 freq[i]--;
//                 dfs(freq,num*10+i);
//                 freq[i]++;
//             }
//         }
//     }
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         vector<int> freq(10,0);
//         for(int digit: digits) freq[digit]++;
//         bool canForm = false;
//         for(int i=0;i<10;i+=2){
//             if(freq[i]!=0){
//                 canForm = true;
//                 break;
//             }
//         }
//         if(!canForm){
//             return vector<int>();
//         }
//         dfs(freq,0);
//         return vector<int>(res.begin(),res.end());
//     }
// };

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> freq(10,0);
            for(int digit: digits) freq[digit]++;
            vector<int> res;
            for(int i=100;i<=999;i++){
                if(i%2==0){
                    int ones = i%10;
                    int tens = (i/10)%10;
                    int hund = i/100;
                    freq[ones]--;
                    freq[tens]--;
                    freq[hund]--;
                    if(freq[ones]>=0 && freq[tens]>=0 && freq[hund]>=0){
                        res.push_back(i);
                    }
                    freq[ones]++;
                    freq[tens]++;
                    freq[hund]++;
                }
            }
            return res;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}