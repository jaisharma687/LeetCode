#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] == 10 || bills[0] == 20){
            return false;
        }
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 20){
                if(ten && five){
                    ten--;
                    five--;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }else if(bills[i] == 10){
                if(!five){
                    return false;
                }else{
                    five--;
                    ten++;
                }
            }else{
                five++;
            }
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}