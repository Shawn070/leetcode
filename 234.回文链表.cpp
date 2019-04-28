/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路：先将链表压入栈，再依次比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        stack<int> s;
        ListNode *pre = head;
        while  (pre != NULL) {
            s.push(pre->val);
            pre = pre->next;
        }
        while (head != NULL) {
            if (s.top() == head->val) {
                head = head->next;
                s.pop();
            } else {
                return false;
            }
        }
        return true;
        }
        
};

