/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树

给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。

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
    map<string, TreeNode*> m;
    set<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        DFS(root);
        return vector<TreeNode*>(res.begin(), res.end());
    }
    string DFS(TreeNode* root) {
        if (root == NULL) return "#";
        //递归 深度优先遍历
        string s = DFS(root->left) + DFS(root->right) + to_string(root->val);
        if (m.count(s))         //找到重复子串
            res.insert(m[s]);   //插入TreeNode
        else
            m[s] = root;        //没有重复子串
        return s;
    }
};

