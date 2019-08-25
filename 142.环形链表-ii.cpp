/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
这个借助画图理解会快很多

当用2倍速的时候，快慢指针相遇在环上某点

参见下图
A-------B-------C
        |       |
        |       |
        E-------D

假设相遇于D点，则快指针应该这时刚好套慢指针一圈（2倍速的必然结果，可以数学证明）

则此时快指针走的路程为 'AB + BCDEB + BD' （用BCDEB表示一圈）(字母序表示方向，AB 表示A -> B)

慢指针走的路程为 'AB + BD'

由于S(快指针) = 2 * S(慢指针) （因为2倍速）（S表示总路程）

==> AB + BCDEB + BD = 2 * (AB + BD) -----(1)

==> AB + BD = BCDEB -----(2)

上式表明此时慢指针走过的全部路径刚好一圈

我们的目标是获得B点这一入环点

又根据一圈的关系 ， 有一圈剩余部分

DB = BCDEB - BD -----(3)

联立式(2)(3)， 有

AB = DB -----(4)

上式表示D到B的距离和A到B的距离是相等的

另一种说法，在慢指针从相遇点D继续向前走DB个长度，
一个新指针从A起始点用同样速度 开始走，两个指针将
会在B点相遇，而B点也正是我们想要的相遇点
*/

/* 方法一：	12 ms	9.8 MB
大致思路：
1. 从head分别以 单步 和 双步 的速度向前走；
2. 在环中间相遇；
3. 分别从 相遇点 和 head 以单步速度向前走；
4. 在入环结点相遇。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCircle = false;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { // D -> B = A -> B
                slow = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};


/* 方法二：	28 ms	12.1 MB
利用set
set介绍：
set是一个储存元素的容器，其中每个元素最多只出现一次，元素遵循一个特
定的顺序。元素一旦被放入次容器将不能被修改（修改元素的值），但是可以
对元素进行插入和移除操作。set内部的元素遵循严格弱排序，因此在寻找元
素的时候比unordered_map稍微慢一些，但是可以直接通过指针操作子分组，
set是一个典型的二分搜索树的应用。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> myset;
        while (head) {
            if (myset.count(head) == 0) 
                myset.insert(head);
            else
                return head;
            head = head->next;
        }
        return NULL;
    }
};
