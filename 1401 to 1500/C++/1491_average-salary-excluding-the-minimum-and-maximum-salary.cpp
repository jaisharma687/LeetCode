#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    double average(vector<int>& salary) {
        int min=salary[0];
        int max=salary[0];
        double sum=salary[0];
        for(int i=1;i<salary.size();i++){
            if(min>salary[i]) min = salary[i];
            if(max<salary[i]) max = salary[i];
            sum += salary[i];
        }
        sum -= max;
        sum -= min;
        double avg = sum / (salary.size()-2);
        return avg;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}