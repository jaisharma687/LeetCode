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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int> res;
        int mx = root->val;
        int prevLevel = -1;
        while(!q.empty()){
            TreeNode* t = q.front().first;
            int nextLevel = q.front().second + 1;
            q.pop();
            if(nextLevel>prevLevel){
                res.push_back(mx);
                mx = INT_MIN;
            }
            prevLevel = nextLevel;
            if(t->left != NULL){
                q.push({t->left,nextLevel});
                mx = max(mx,t->left->val);
            }
            if(t->right != NULL){
                q.push({t->right,nextLevel});
                mx = max(mx,t->right->val);
            }
        }
        return res;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();