/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (53.71%)
 * Total Accepted:    58.2K
 * Total Submissions: 108.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0); //以0链表开头
        ListNode* head = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                res->next = l1;    //注意->next后更新当前节点为下一链表节点
                res = res->next;
                l1 = l1->next;
            }else{
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL && l2 != NULL) {
            res->next = l2;
            res = res->next;
        }
        if(l1 != NULL && l2 == NULL) {
            res->next = l1;
            res = res->next;
        }
        return head->next; //略过0开头节点
    }
};
