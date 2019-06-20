/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        return create(preorder, inorder, 0, inorder.size() - 1, 0);
    }
    // low high 为inorder的搜索范围，index 为preorder的检索位置
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int low, int high, int index) {
        if (low > high) return nullptr;
        TreeNode* node = new TreeNode(preorder[index]);
        if (low == high) return node;

        // pos 为inorder检索到的位置
        int pos = 0;
        for (int i = low; i <= high; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left  = create(preorder, inorder, low, pos - 1, index + 1);
        // + (pos - low) 跳过 preorder 中已经在上一个 create 中加入过的结点
        node->right = create(preorder, inorder, pos + 1, high, index + 1 + (pos - low));
        return node;
    }
};

