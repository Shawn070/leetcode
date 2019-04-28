/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 思路1: 递归
class Solution {
public:
   vector<int> res;
   vector<int> inorderTraversal(TreeNode* root) {
       if (root) {
           inorderTraversal(root->left);
           res.push_back(root->val);
           inorderTraversal(root->right);
       }
       return res;
   }
};

// 思路2：
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (s.size() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            if (s.size()) {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        
        return res;
    }
};

