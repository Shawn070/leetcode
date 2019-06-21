/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(0, inorder.size() - 1, postorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* create(int low, int high, int index, vector<int>& inorder, vector<int>& postorder) {
        if (low > high) return nullptr;
        TreeNode* node = new TreeNode(postorder[index]);
        if (low == high) return node;
        int pos = 0;
        for (int i = low; i <= high; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->right = create(pos + 1, high, index - 1, inorder, postorder);
        node->left = create(low, pos - 1, index - 1 - (high - pos), inorder, postorder);
        return node;
    }
};

