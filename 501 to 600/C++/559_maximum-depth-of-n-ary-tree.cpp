#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public:
        int maxDepth(Node* root) {
            int depth = 0;
            if(root==nullptr){
                return 0;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                depth++;
                int l = q.size();
                for(int i=0;i<l;i++){
                    auto node = q.front();
                    q.pop();
                    vector<Node*> v = node->children;
                    for(Node* n: v){
                        if(n!=nullptr){
                            q.push(n);
                        }
                    }
                }
            }
            return depth;
        }
    };

class Solution {
    public:
        int maxDepth(Node* root) {
            if(root==nullptr){
                return 0;
            }
            int md = 0;
            for(auto child: root->children){
                md = max(md,maxDepth(child));
            }
            return 1+ md;
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