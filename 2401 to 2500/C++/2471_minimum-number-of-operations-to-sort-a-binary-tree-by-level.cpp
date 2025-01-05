#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countMinSwaps(vector<int> &arr){
        int n = arr.size();
        int swaps = 0;
        vector<pair<int,int>> arrPos(n);
        for(int i=0;i<n;i++){
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }
        sort(arrPos.begin(),arrPos.end());
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i] && arrPos[i].second!=i){
                int cycles = 0;
                int j = i;
                while(!visited[j]){
                    visited[j] = true;
                    j = arrPos[j].second;
                    cycles ++;
                }
                if(cycles>0){
                    swaps += (cycles-1);
                }
            }
        }
        return swaps;
    }
    int solveBT(TreeNode* root){
        int swaps = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int> nodes;
        int prevLevel = 0;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int nextLevel = q.front().second+1;
            q.pop();
            if(nextLevel>prevLevel){
                swaps+= countMinSwaps(nodes);
                nodes = {};
            }
            prevLevel = nextLevel;
            if(temp->left != NULL){
                q.push({temp->left,nextLevel});
                nodes.push_back(temp->left->val);
            }
            if(temp->right != NULL){
                q.push({temp->right,nextLevel});
                nodes.push_back(temp->right->val);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        return solveBT(root);
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();