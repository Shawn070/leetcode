/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.00%)
 * Total Accepted:    37.9K
 * Total Submissions: 114.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */
/*
* 一次遍历算法:
* 上述算法可以优化为只使用一次遍历。我们可以使用两个指针而不是一个指针。
* 第一个指针从列表的开头向前移动 n+1 步，而第二个指针将从列表的开头
* 出发。现在，这两个指针被 n 个结点分开。我们通过同时移动两个指针向前
* 来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将
* 指向从最后一个结点数起的第 n 个结点。我们重新链接第二个指针所引用的结
* 点的 next 指针指向该结点的下下个结点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* node_pre = head;
        for(int i = 0; i < n + 1; ++i){ //遍历链表到n + 1，判断n是否大于链表长度
            if(node == NULL){           //当n大于链表长度时，删除头节点
                node = head;
                head = head->next;
                delete node;
                return head;
            }
            node = node->next;
        }
        while(node != NULL){ //遍历从链表位置n + 1到链表末尾，同时移动两节点
            node = node->next;          //node - node_pre = n
            node_pre = node_pre->next;  //node_pre 向后移动 (max - n) 等于向前移动 max - (max - n)
        }
        node = node_pre->next; //跳过删除节点
        node_pre->next = node->next; //等价于 node_pre->next = node_pre->next-next;
        delete node;
        return head;
    }
};

