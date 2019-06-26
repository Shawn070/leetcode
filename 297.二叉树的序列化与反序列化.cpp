/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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

//方法一：
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#_";
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        string item;
        queue<string> q;
        while (std::getline(ss, item, '_'))
            q.push(item);
        return helper(q);
    }
    
    TreeNode* helper(queue<string>& q) {
        string val = q.front();
        q.pop();
        if (val == "#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};

//方法二：（未实现）
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize2(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize2(in);
    }

private:
    void serialize2(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << " ";
            serialize2(root->left, out);
            serialize2(root->right, out);
        } else {
            out << "#";
        }
    }
    
    TreeNode* deserialize2(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize2(in);
        root->right = deserialize2(in);
        return root;
    }
};
