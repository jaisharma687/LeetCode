#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0;
        int n = rating.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i] < rating[j] && rating[j] < rating[k])||
                        (rating[i] > rating[j] && rating[j] > rating[k])) teams++;
                }
            }
        }
        return teams;
    }
};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0;
        int n = rating.size();
        for(int i=0;i<n;i++){
            int leftSmall = 0,leftBig = 0,rightSmall = 0,rightBig = 0;
            int val = rating[i];
            for(int j=i-1;j>=0;j--){
                if(val > rating[j]) leftSmall++;
                if(val < rating[j]) leftBig++;
            }
            for(int j=i+1;j<n;j++){
                if(val > rating[j]) rightSmall++;
                if(val < rating[j]) rightBig++;
            }
            teams += leftSmall*rightBig + leftBig*rightSmall;
        }
        return teams;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}