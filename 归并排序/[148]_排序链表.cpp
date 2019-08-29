#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head || head->next) return head;
        //快慢指针
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //将链表分为两个部分
        fast = slow->next;  // fast 指向后半部分
        slow->next = NULL;  // slow 最后指向空

        return merge(sortList(head), sortList(fast));
    }

    //递归实现
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        if (l1->val <= l2->val) {
            l1->next = merge2(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2(l1, l2->next);
            return l2;
        }
    }

    //非递归实现
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dump(0);
        ListNode* cur = &dump;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;

        return dump.next;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    ListNode* list = head;
    list->next = new ListNode(5);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(6);
    list = list->next;
    list->next = new ListNode(8);
    list = list->next;
    list->next = new ListNode(1);

    Solution s;
    s.sortList(head);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    int t;
    cin >> t;
    return 0;
}
