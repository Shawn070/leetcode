#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* end = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return end;

	}
};

int main() {
	ListNode *L = new ListNode(-1), *head = L;
	for (int i = 1; i < 10; i++) {
		L->next = new ListNode(i);
		L = L->next;
	}
	Solution S;
	ListNode* res = S.reverseList(head->next);
	return 0;
}