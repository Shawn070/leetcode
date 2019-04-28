/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历

给定一个二叉树，返回它的 前序 遍历。

四种基本的遍历思想为：

前序遍历：根结点 ---> 左子树 ---> 右子树

中序遍历：左子树---> 根结点 ---> 右子树

后序遍历：左子树 ---> 右子树 ---> 根结点

层次遍历：仅仅需按层次遍历就可以

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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

/*
// 思路1：递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
    void pre(TreeNode *root, vector<int> &res) {
        if (!root) return ;
        res.push_back(root->val);
        pre(root->left, res);
        pre(root->right, res);
    }
    }
};
*/

// 思路2：栈
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         TreeNode* cur = root;
//         stack<TreeNode*> s;
//         while (cur || !s.empty()) {
//             if (cur) {                   // 当前节点存在，
//                 s.push(cur);             // 压入当前节点
//                 res.push_back(cur->val); // 存放当前值
//                 cur = cur->left;         // 遍历左树
//             } else {                 // 遍历到空节点
//                 cur = s.top();
//                 s.pop();             // 弹出上一节点
//                 cur = cur->right;    // 遍历右树
//             }
//         }
//         return res;
//     }
// };

// 思路3：栈，最初放入root, 每次弹出根节点，然后先放入右子节点，再放入左子节点。
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            if (temp) {
                res.push_back(temp->val);
                s.push(temp->right);
                s.push(temp->left);
            }
        }
        return res;
    }
};
