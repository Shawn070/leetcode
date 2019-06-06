/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表

    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

    示例 1:

    输入: 4->2->1->3
    输出: 1->2->3->4
    示例 2:

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5

 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
归并排序的基本思想是：找到链表的middle节点，然后递归
对前半部分和后半部分分别进行归并排序，最后对两个以排好
序的链表进行Merge。
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //将链表分为两个部分
        fast = slow->next;  // fast 指向后半部分
        slow->next = NULL;  // slow 最后指向空

        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dump(0);
        ListNode* cur = &dump;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;

        return dump.next;
    }
};

