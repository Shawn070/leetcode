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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //将链表分为两个部分
        fast = slow->next;  // fast 指向后半部分
        slow->next = NULL;  // slow 最后指向空

        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dump(0);
        ListNode* cur = &dump;

        while (l1 != NULL && l2 != NULL) {
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
        if (l1 != NULL)
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
