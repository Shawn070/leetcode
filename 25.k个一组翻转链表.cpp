/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] k个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (50.47%)
 * Total Accepted:    9.1K
 * Total Submissions: 18K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
 tmp = head

              --------------            
              |            |
 pre→    head→    →next→    →next
     |           |      ↓       
     -------------     tmp   

pre  = head
head = head->next          
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        dummy->next = head;
        int len = length(head);
        for (int i=0; i < len/k; ++i){
            for (int j=1; j < k; ++j){
                ListNode* tmp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = tmp;
            }
            pre  = head;
            head = head->next;
        }
        return dummy->next;
    }
private:
    ListNode *dummy = new ListNode(0), *pre = dummy;
    int length(ListNode *head){ //获取链表长度
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

