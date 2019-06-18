/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 

 

示例：

输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。

 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

// 1(r) -> 2(r) -> 3(r)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        //1(r) -> 1 -> 2(r) -> 2 -> 3(r) -> 3
        Node *iter = head;
        while (iter) {
            Node *n = new Node(iter->val, iter->next, nullptr);
            Node *tmp = iter->next;
            iter->next = n;
            iter = tmp;
        }
        //1(r) -> 1(r) -> 2(r) -> 2(r) -> 3(r) -> 3(r)
        iter = head;
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        // 1(r) -> 2(r) -> 3(r) ===>> old
        // 1(r) -> 2(r) -> 3(r) ===>> new
        Node *ret = head->next;
        iter = head;
        while (iter->next) {
            Node *tmp = iter->next;
            iter->next = iter->next->next;
            iter = tmp;
        }
        return ret;
    }
};

