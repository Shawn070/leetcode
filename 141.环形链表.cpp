/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 * 
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。


示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路1：使用快慢指针，若指针相遇则判断有环
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != NULL){
            if (fast == slow)
                return true;
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
        }
        return false;
     }
};
*/

// 思路2：利用set
/* set介绍：
set是一个储存元素的容器，其中每个元素最多只出现一次，元素遵循一个特
定的顺序。元素一旦被放入次容器将不能被修改（修改元素的值），但是可以
对元素进行插入和移除操作。set内部的元素遵循严格弱排序，因此在寻找元
素的时候比unordered_map稍微慢一些，但是可以直接通过指针操作子分组，
set是一个典型的二分搜索树的应用。

常用操作：
1.元素插入：myset.insert()
2.中序遍历：类似vector遍历（用迭代器）
3.反向遍历：利用反向迭代器reverse_iterator。
    例：
    set<int> s;
    ......
    set<int>::reverse_iterator rit;
    for(rit=s.rbegin();rit!=s.rend();rit++)
4.元素删除：与插入一样，可以高效的删除，并自动调整使红黑树平衡。
            set<int> s;
            s.erase(2);        //删除键值为2的元素
            s.clear();
5.元素检索：find()，若找到，返回该键值迭代器的位置，否则，返回最后一个元素后面一个位置。
            set<int> s;
            set<int>::iterator it;
            it=s.find(5);    //查找键值为5的元素
            if(it!=s.end())    //找到
                cout<<*it<<endl;
            else            //未找到
                cout<<"未找到";
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> myset;
        while(head){
            if(myset.count(head)==0)
                myset.insert(head);
            else
                return true;
            head = head->next;
        }
        return false;
    }
};
