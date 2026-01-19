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
    vector<int> ans;
    void helper(Node* node){
        if(!node) return;
        for(auto child:node->children){
            ans.push_back(child->val);
            helper(child);
        }
    }
    vector<int> preorder(Node* root) {
        
        if(!root) return ans;
        ans.push_back(root->val);
        helper(root);
        return ans;
    }
};