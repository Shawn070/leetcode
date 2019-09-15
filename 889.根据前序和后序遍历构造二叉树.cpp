/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty() || post.empty()) return nullptr;
        return create(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode* create(vector<int>& pre, vector<int>& post, int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2) return nullptr;
        TreeNode* node = new TreeNode(pre[l1]);
        if (l1 == r1) return node;
        int pos = 0;
        for (int i = l2; i <= r2; i++) {
            if (post[i] == pre[l1 + 1]) {
                pos = i;
                break;
            }
        }
        /*
        pre: [1,2,4,5,3,6,7], [l1, ... , r1] -> [l1 + 1， l1 + 1 + pos - l2] + [l1 + 1 + pos - l2 + 1, r1]
        post:[4,5,2,6,7,3,1], [l2, ... , r2] -> [l2, pos] + [pos + 1, r2 - 1]
        */
        node->left = create(pre, post, l1 + 1, l1 + 1 + pos - l2, l2, pos);
        node->right = create(pre, post, l1 + 1 + pos - l2 + 1, r1, pos + 1,r2 - 1);

        return node;
    }
};
