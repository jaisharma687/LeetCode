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
    void bfs(TreeNode* root){
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<TreeNode*> nodes;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int nxtlevel = q.front().second+1;
            q.pop();
            if(nxtlevel%2==0){
                int i = 0;
                int j = nodes.size()-1;
                while(i<j){
                    int x = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = x;
                    i++;
                    j--;
                }
                while(nodes.size()!=0){
                    nodes.pop_back();
                }
            }
            if(temp->left != NULL){
                q.push({temp->left,nxtlevel});
                if(nxtlevel%2!=0){
                    nodes.push_back(temp->left);
                }
            }
            if(temp->right != NULL){
                q.push({temp->right,nxtlevel});
                if(nxtlevel%2!=0){
                     nodes.push_back(temp->right);
                }
            }
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int levels = 0;
        bfs(root);
        return root;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();