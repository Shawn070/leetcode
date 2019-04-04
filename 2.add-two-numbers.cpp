/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.56%)
 * Total Accepted:    85.1K
 * Total Submissions: 261.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // ListNode *p1=l1, *p2=l2, *l3=NULL;
        // ListNode *pre = NULL, *p3 = l3;
        // int carried = 0;
        
        // while(p1 || p2){
        //     int a = p1 ? p1->val : 0;
        //     int b = p2 ? p2->val : 0;
        //     if(p1)
        //         p1->val = (a + b + carried)%10;
        //     else{
        //         pre->next = new ListNode((a+b+carried)%10);
        //         p1 = pre->next;
        //     }
        //     // p3 = new ListNode((a + b + carried)%10);
        //     carried = (a+b+carried)/10;
        //     pre = p1;
        //     p1 = p1->next;
        //     if(p2) p2 = p2->next;
        // }
        // pre->next = carried ? new ListNode(1) : NULL;
        // return l1;

        ListNode *result = new ListNode(0);
        ListNode *temp = result;
        int sum = 0;
        while(l1 || l2){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(sum%10);
            sum /= 10;
            temp = temp->next;
        }
        if(sum){
            temp->next = new ListNode(sum);
        }
        return result->next;
    }
};
