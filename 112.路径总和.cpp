/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] ????

?????????????????????????????????????????????????????

??: ???????????????

??: 
????????????? sum = 22?

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
?? true, ???????? 22 ???????????? 5->4->11->2?

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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum - root->val == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

