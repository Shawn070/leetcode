/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II

给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

 

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路：用栈 s1，s2 反向存储，s3存储相加后的值
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, s3;
        while (l1 != NULL) {s1.push(l1->val); l1=l1->next;}
        while (l2 != NULL) {s2.push(l2->val); l2=l2->next;}
        int n1 = s1.size(), n2 = s2.size();
        ListNode *res = new ListNode(0);
        ListNode *pre = res;
        int carry = 0, sum = 0;
        while (n1 > 0 || n2 > 0 || carry > 0) {
            sum = 0;
            if (n1 > 0) {sum += s1.top(); s1.pop(); n1--;}
            if (n2 > 0) {sum += s2.top(); s2.pop(); n2--;}
            sum += carry;
            s3.push(sum % 10);
            carry = sum / 10;
        }
        int n3 = s3.size();
        while (n3 > 0) {
            res->next = new ListNode(s3.top());
            res = res->next;
            s3.pop();
            n3--;
        }
        return pre->next;
    }
};



