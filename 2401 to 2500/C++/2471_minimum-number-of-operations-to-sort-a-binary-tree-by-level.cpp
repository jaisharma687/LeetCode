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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            int n = size;
            vector<int> nodes;
            while(size--){
                auto node = q.front();
                q.pop();
                nodes.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            unordered_map<int,int> mpp;
            for(int i=0;i<n;i++){
                mpp[nodes[i]] = i;
            }
            vector<int> sortedVec(nodes.begin(), nodes.end());
            sort(sortedVec.begin(), sortedVec.end());
            int swaps = 0;
            for(int i=0;i<n;i++){
                if(nodes[i]!=sortedVec[i]){
                    int j = mpp[sortedVec[i]];
                    mpp[nodes[i]] = j;
                    mpp[sortedVec[i]] = i;
                    swap(nodes[i], nodes[j]);
                    swaps++;
                }
            }
            res += swaps;
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