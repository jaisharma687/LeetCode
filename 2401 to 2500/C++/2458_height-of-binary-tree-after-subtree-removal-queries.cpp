#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Definition for a binary tree node.
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
    int level[100001];
    int height[100001];
    int levelMaxHeight[100001];
    int levelSecondMaxHeight[100001];
    int dfs(TreeNode* root, int lev){
        if(root==nullptr) return 0;
        int lh = dfs(root->left, lev+1);
        int rh = dfs(root->right, lev+1);
        level[root->val] = lev;
        height[root->val] = 1 + max(lh,rh);
        if(levelMaxHeight[lev]<height[root->val]){
            levelSecondMaxHeight[lev] = levelMaxHeight[lev];
            levelMaxHeight[lev] = height[root->val];
        }else if(levelSecondMaxHeight[lev]<height[root->val]){
            levelSecondMaxHeight[lev] = height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> res;
        for(int& node: queries){
            int nodeLevel = level[node];
            int nodeHeight = height[node];
            if(nodeHeight == levelMaxHeight[nodeLevel]){
                res.push_back(nodeLevel+levelSecondMaxHeight[nodeLevel]-1);
            }
            else{
                res.push_back(nodeLevel+levelMaxHeight[nodeLevel]-1);
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

