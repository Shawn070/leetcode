/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II

给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例：


输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

//层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node* cur = new Node(-1);
            Node* tmp;
            for (int i = 0; i < size; i++) {
                cur->next = q.front();
                cur = cur->next;
                tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};

//递归
class Solution {
public:
    Node* getNextNode(Node* cur) {
        while(cur) {
            if (cur->left) return cur->left;
            if (cur->right) return cur->right;
            cur = cur->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        Node* cur = root;
        while (cur) {
            Node* tmp = cur;
            while (tmp) {
                if (tmp->left) {
                    if (tmp->right) 
                        tmp->left->next = tmp->right;
                    else 
                        tmp->left->next = getNextNode(tmp->next);
                }
                if (tmp->right)
                    tmp->right->next = getNextNode(tmp->next);
                tmp = tmp->next;
            }
            cur = getNextNode(cur);
        }
        return root;
    }
};

//双结点遍历
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* dummy = new Node(-1, NULL, NULL, NULL);
        Node* pre = dummy;
        Node* head  = root;
        
        while (root) {
            if (root->left) {
                pre->next = root->left;
                pre = pre->next;
            }
            if (root->right) {
                pre->next = root->right;
                pre = pre->next;
            }
            
            root = root->next;
            
            if (!root) {
                pre = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head;
    }
};

