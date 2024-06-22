#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "C"){
                score.pop_back();
            }else if(operations[i] == "D"){
                int top = score.back();
                score.push_back(top*2);
            }else if(operations[i] == "+"){
                int top1 = score.back();
                score.pop_back();
                int top2 = score.back();
                score.push_back(top1);
                score.push_back(top1+top2);
            }else{
                score.push_back(stoi(operations[i]));
            }
        }
        int sum = 0;
        for(int i=0;i<score.size();i++){
            sum += score[i];
        }
        return sum;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}