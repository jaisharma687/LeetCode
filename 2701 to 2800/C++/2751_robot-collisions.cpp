#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> loc = positions;
        int n = positions.size();
        vector<tuple<int,int,char>> v;
        for(int i=0;i<n;i++) v.push_back({positions[i],healths[i],directions[i]});
        sort(v.begin(),v.end());
        /*
        tuples will be sorted in lexicographical order by default. Lexicographical 
        order means that the tuples will be compared element by element from 
        left to right, using the default comparison for each type.
        */
        int a,b; 
        char c;
        vector<vector<int>> robot;
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            tie(a,b,c) = v[i];
            if(c=='R') robot.push_back({a,b});
            else{
                if(robot.size()==0) temp.push_back({a,b});
                else while(robot.size()!=0){
                    if(robot.back()[1] > b){
                        vector<int> top = robot.back();
                        robot.pop_back();
                        robot.push_back({top[0],top[1]-1});
                        b = 0;
                        break;
                    }else if(robot.back()[1] == b){
                        robot.pop_back();
                        b = 0;
                        break;
                    }else{
                        robot.pop_back();
                        b--;
                    }
                }
                if(b) temp.push_back({a,b});
            }
        }
        while(robot.size()!=0){
            temp.push_back(robot.back());
            robot.pop_back();
        }
        map<int,int> m;
        for(auto i:temp) m[i[0]] = i[1];
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(m[loc[i]]) ans.push_back(m[loc[i]]);
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}