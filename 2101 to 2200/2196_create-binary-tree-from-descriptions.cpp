#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodes;
        vector<int> children;
        for(auto x: descriptions){
            int p = x[0];
            int c = x[1];
            int l = x[2];
            children.push_back(c);
            if(nodes.count(p) == 0){
                TreeNode* parent = new TreeNode(p);
                nodes[p] = parent;
            }
            if(nodes.count(c)==0){
                TreeNode* child = new TreeNode(c);
                nodes[c] = child;
            }
            if(l==1) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];
        }
        TreeNode * ans = NULL;
        for(auto x:descriptions){
            if (find(children.begin(), children.end(), x[0]) == children.end()) {
                ans = nodes[x[0]];
                break;
            }
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}