/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表

    编写一个程序，找到两个单链表相交的起始节点。

    注意：

    如果两个链表没有交点，返回 null.
    在返回结果后，两个链表仍须保持原有的结构。
    可假定整个链表结构中没有循环。
    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/**
定义两个指针, 第一轮让两个到达末尾的节点指向另一个链表的头部, 最后如果相遇则
为交点(在第一轮移动中恰好抹除了长度差)
两个指针等于移动了相同的距离, 有交点就返回, 无交点就是各走了两条指针的长度
**/
        ListNode* a = headA,* b = headB;
// 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头, 而第二轮体现在
// 如果pA或pB相交就返回交点, 不相交最后就是 NULL==NULL
        while (a != b) {
            a = (a == NULL ? headB : a->next);
            b = (b == NULL ? headA : b->next);
        }
        return a;
    }
};

