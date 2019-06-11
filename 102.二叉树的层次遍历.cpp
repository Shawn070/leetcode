/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
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

/*
层序遍历一般来说确实是用队列实现的，但是这里很明显用递归前序遍历就能实现呀，而且复杂度O(n)。

要点有几个：

利用depth变量记录当前在第几层（从0开始），进入下层时depth + 1；
如果depth >= vector.size()说明这一层还没来过，这是第一次来，所以得扩容咯；
因为是前序遍历，中-左-右，对于每一层来说，左边的肯定比右边先被遍历到，实际上后序中序都是一样的。
*/

// 思路1：队列queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);   // 每层以NULL结束
        vector<int> cur_vec;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL) {    // 每层以NULL结束
                ans.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);   // 每层以NULL结束
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return ans;
    }
};

// 思路2：遍历每一层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                row[i] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// 思路3：递归前序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        pre(root, 0, ans);
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

