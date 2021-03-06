/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (58.77%)
 * Total Accepted:    18K
 * Total Submissions: 30.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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

/*
   ---------------
   |             |
    → head →    next    → ......
           |           |
           -------------
*/

//递归：（12 ms	8.4 MB）
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;    // 当前或下一个节点为空则停止交换
        }
        ListNode* next = head->next; //取下一个节点
        head->next = swapPairs(next->next); //将下下节点与下下下节点比较，并将排序好的链表连接到head后
        next->next = head;          //注意两个 ->next 的使用
        return next;
    }
};

//遍历：（16 ms	8.7 MB）
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head;
        ListNode* tmp;
        while(head && head->next){
            tmp = head;
            head = head->next;
            head->next = tmp;
        }
        return res;
    }
};

