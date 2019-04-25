/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 思路：迭代方法
 * 1 -> 2 -> 3 -> 4 -> null
 * null <- 1 <- 2 <- 3 <- 4
 * 
 * complete:https://mp.weixin.qq.com/s?__biz=MzUyNjQxNjYyMg==&mid=2247483799&idx=1&sn=c2212c8963809e8d3392abeeb851dbfc&chksm=fa0e6e16cd79e7003c2d30b1a2bb4f23dc56df38e3efedd0ab2cfae291609280a832eabe67de&scene=21#wechat_redirect
 * gif url:https://camo.githubusercontent.com/e740a8574bcc8fbf8e433c06c017e6235d6b10e7/68747470733a2f2f646979636f64652e62302e7570616979756e2e636f6d2f70686f746f2f323031382f30653062336134623130333163336263663136626431323430656263353731612e676966
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL;
        while (head) {      // 每次倒转一个指向
            ListNode *next = head -> next; //临时节点，暂存当前节点的下一节点，用于后移
            head -> next = cur; //将当前节点指向它前面的节点
            cur = head;         //前指针后移，用于下次
            head = next;        //当前指针后移，并连接，用于下次
        }
        return cur;
    }
};

