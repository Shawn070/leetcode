/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历

给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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

//方法一：递归
public:
    vector<int> postorderTraversal(TreeNode* root) {

       vector<int> res;
       inorder(root, res);
       return res;
   }
   void inorder(TreeNode* root, vector<int> &res) {
       if (!root) return ;
       inorder(root->left, res);
       inorder(root->right, res);
       res.push_back(root->val);
   }
};
//方法二：递归
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> l = postorderTraversal(root->left);
        vector<int> r = postorderTraversal(root->right);
        l.insert(l.end(), r.begin(), r.end());
        l.push_back(root->val);
        return l;
        }
};
//方法二：遍历
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s{{root}};
        TreeNode* head = root;
        while (!s.empty()) {
            TreeNode* t = s.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                res.push_back(t->val);
                s.pop();
                head = t;
            } else {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
            }
        }
        return res;


    }
};

