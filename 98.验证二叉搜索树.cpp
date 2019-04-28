/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
    
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

// 思路1：递归比较
/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (nullptr == root) return true;
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isValidBST(TreeNode *root, long mn, long mx) {
        if (nullptr == root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return _isValidBST(root->left, mn, root->val) && _isValidBST(root->right , root->val, mx);
    }
};
*/

// 思路2：中序遍历为升序
class Solution {
public:
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        if (nullptr == root) return true;
        inorder(root);
        for (int i=0; i < res.size() - 1; i++) {
            if (res[i] < res[i+1]) {
                continue;
            }
            return false;
        }
        return true;
    }

    vector<int> inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }
        return res;
    }
};
