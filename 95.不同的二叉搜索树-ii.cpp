/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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

// 递归:(60 ms	17.2 MB)
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            allTrees.push_back(NULL);
            return allTrees;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    allTrees.push_back(cur);
                }
            }
        }
        return allTrees;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>{};
        return generateTrees(1, n);
    }
};


// 递归 + 记忆: (36 ms	12.7 MB)
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end, map<pair<int, int>, vector<TreeNode*>>& mem) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            allTrees.push_back(NULL);
            return allTrees;
        }
        if (mem.find(make_pair(start, end)) != mem.end()) {
            return mem[make_pair(start, end)];
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1, mem);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end, mem);
            
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    allTrees.push_back(cur);
                }
            }
        }
        mem[make_pair(start, end)] = allTrees;
        return allTrees;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        map<pair<int, int>, vector<TreeNode*>> mem;

        return generateTrees(1, n, mem);
    }
};
