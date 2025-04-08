#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// class Solution {
// public:
//     vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
//     int solveForQuery(vector<vector<int>>& grid, int query, int m, int n){
//         int pts = 0;
//         vector<vector<int>> visited(m,vector<int>(n,0));
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         if(grid[0][0] < query){
//             while(!q.empty()){
//                 pair<int,int> xy = q.front();
//                 q.pop();
//                 if(!visited[xy.first][xy.second] && grid[xy.first][xy.second]<query) pts++;
//                 visited[xy.first][xy.second]=1;
//                 for(int i=0;i<4;i++){
//                     pair<int,int> pq={xy.first+ dir[i].first,xy.second+ dir[i].second};
//                     int x = pq.first;
//                     int y = pq.second;
//                     cout<< x<< " "<<y<<endl;
//                     if(x>=0 && x<m && y>=0 && y<n && grid[x][y]<query && !visited[x][y]){
//                         q.push({x,y});
//                     }
//                 }
//             }
//         }
//         return pts;
//     }   

//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int> answer;
//         for(int query: queries){
//             answer.push_back(solveForQuery(grid,query, m, n));
//         }
//         return answer;
//     }
// };

class Solution {
    public:
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size();
            int n = grid[0].size();
            vector<pair<int,int>> sQ;
            int qS = queries.size();
            for(int i=0;i<qS;i++){
                sQ.push_back({queries[i],i});
            }
            sort(sQ.begin(),sQ.end());
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> heap;
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            heap.push({grid[0][0],{0,0}});
            visited[0][0] = true;
            int pts = 0;
            vector<int> ans(qS,0);
            for(auto&[qVal, qIdx]:sQ){
                while(!heap.empty() && heap.top().first<qVal){
                    pts++;
                    auto[val,pos] = heap.top();
                    int x = pos.first;
                    int y = pos.second;
                    heap.pop();
                    for(auto[dx,dy]:dir){
                        int r = dx+x;
                        int c = dy+y;
                        if(r>=0 && c>=0 && r<m && c <n && !visited[r][c]){
                            visited[r][c] = true;
                            heap.push({grid[r][c],{r,c}});
                        }
                    }
                }
                ans[qIdx] = pts;
            }
            return ans;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();