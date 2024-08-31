/*
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
*/

class Solution {
public:
    void postorderTraversal(Node * head, vector<int> &out){
        if(head != NULL){
            for(auto x: head->children){
                if(x!=NULL) postorderTraversal(x,out);
            }
            out.push_back(head->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderTraversal(root,res);
        return res;
    }
};