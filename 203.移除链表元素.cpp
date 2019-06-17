/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *root = head;
        ListNode *pre;
        while(head) {
            if (head->val == val) {
                if (head == root) {
                    head = head->next;
                    root = head;
                    continue;
                } else {
                    pre->next = head->next;
                    head = pre->next;
                    continue;
                }
            }
            pre  = head;
            head = head->next;
        }
        return root;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *rootPre = new ListNode(0);
        rootPre->next = head;
        ListNode *cur = rootPre;
        while (cur && cur->next) {
            if (cur->next->val == val) 
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return rootPre->next;
    }
};
