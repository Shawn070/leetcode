/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 * 
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

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
    int maxDepth(TreeNode* root) {
        class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 思路1：递归
        //return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
        
        // 
        if (root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right) ? (left + 1) : (right + 1);
    }
};
    }
};

