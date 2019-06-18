/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *p1, *tmp;
        p1 = head;
        while (p1) {
            if (p1->child) {
                tmp = p1->next;
                p1->next = p1->child;
                p1->child->prev = p1;
                while (p1->child->next)
                    p1->child = p1->child->next;
                p1->child->next = tmp;
                if (tmp)
                    tmp->prev = p1->child;
                p1->child = NULL;
            }
            p1 = p1->next;
        }
        return head;
    }
};

