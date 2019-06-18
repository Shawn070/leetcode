/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] ????

??????????????????????? k ?????? k ?????

?? 1:

??: 1->2->3->4->5->NULL, k = 2
??: 4->5->1->2->3->NULL
??:
???? 1 ?: 5->1->2->3->4->NULL
???? 2 ?: 4->5->1->2->3->NULL
?? 2:

??: 0->1->2->NULL, k = 4
??: 2->0->1->NULL
??:
???? 1 ?: 2->0->1->NULL
???? 2 ?: 1->2->0->NULL
???? 3 ?: 0->1->2->NULL
???? 4 ?: 2->0->1->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode *cur = head;
        while (cur->next) {
             n++;
             cur = cur->next;
        }
        ListNode *tail = cur;
        k = k % n;
        if (k == 0) return head;
        int cnt = 0;
        cur = head;
        while (cnt < n - k - 1) {
            cur = cur->next;
            cnt++;
        }
        ListNode *ret = cur->next;
        cur->next = nullptr;
        tail->next = head;
        return ret;
    }
};

