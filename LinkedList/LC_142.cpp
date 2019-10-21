/* �������� II */
#include <iostream>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode * detectCycle(ListNode* head) {
		// �߽�����
		if (head == NULL) return NULL;
		if (head->next == NULL) return NULL;
		if (head->next->next == NULL) return NULL;

		// �������ָ��
		ListNode* a = head->next;
		ListNode* b = head->next->next;
		// ����ָ������ֱ������
		while (a != NULL && b != NULL) {
			if (a == b) break;
			a = a->next;
			b = b->next;
			if (b != NULL) b = b->next;
		}
		// ���a����b��һ��ΪNone����ʾû�л�
		if (a == NULL || b == NULL) {
			return NULL;
		}
		// Ѱ��������
		b = head;
		while (a != b) {
			a = a->next;
			b = b->next;
		}
		return a;
	}
};

//int main()
//{
//	ListNode* head = new ListNode(-1);
//	ListNode* p = head;
//	char c;
//	while ((c = getchar()) != '\n') {
//		if (c != ' ') {
//			ungetc(c, stdin);
//			int x = 0;
//			cin >> x;
//			ListNode* node = new ListNode(x);
//			p->next = node;
//			p = p->next;
//		}
//	}
//	head = head->next;
//
//	int pos = 0;
//	cin >> pos;
//	ListNode* p2 = head;
//	for (int i = 0; i < pos; i++) {
//		p2 = p2->next;
//	}
//	p->next = p2;
//
//	Solution sol = Solution();
//	ListNode* res = sol.detectCycle(head);
//	cout << res->val << endl;
//
//	return 0;
//}
