/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

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


// 思路1：层序遍历后翻转
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        pre(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void pre(TreeNode* root, int depth, vector<vector<int>> &ans) {
        if (!root) return ;
        if (depth >= ans.size())
            ans.push_back(vector<int> {});
        ans[depth].push_back(root->val);
        pre(root->left, depth + 1, ans);
        pre(root->right, depth + 1, ans);
    }
};


// 思路2：直接通过深度ans[level]倒序压入（顺序遍历，倒序压入）
class Solution {
public:
    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    void levelOrder(vector<vector<int>> &ans, TreeNode* node, int level) {
        if (!node) return ;
        ans[level].push_back(node->val);
        levelOrder(ans, node->left, level - 1);
        levelOrder(ans, node->right, level - 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);    // 得到深度
        vector<vector<int>> ans(d, vector<int> {}); // 通过深度建立ans
        levelOrder(ans, root, d - 1);
        return ans;
    }
};
