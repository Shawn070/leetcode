/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (44.47%)
 * Total Accepted:    19K
 * Total Submissions: 42.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin()); //删除lists[0]
            lists.erase(lists.begin()); //删除lists[1]
        }
        return lists.front();
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/*
begin()函数和end()位于iteartor； “[begin, end)”，end是最后一个元素的后一个位置。
而front()和back()位于vector list deque and etc… 
容器中末尾元素的迭代器
容器中末尾元素的引用
*/

