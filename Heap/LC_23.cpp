/* 合并K个排序链表 */
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct node_cmp
{
	bool operator()(const ListNode* a, const ListNode* b) const
	{
		return a->val > b->val;
	}
};

class Solution
{
public:
	ListNode * mergeLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, node_cmp > heap;
		// push head of lists into heap
		for (ListNode* head : lists) {
			if (head == NULL)	continue;
			heap.push(head);
		}

		ListNode* head = NULL;
		ListNode* tail = NULL;
		while (heap.size() > 0)
		{
			// get min node
			ListNode* node = heap.top();
			heap.pop();
			// add node to result linked list
			if (head == NULL) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = tail->next;
			}
			// get next node of current added node
			ListNode* next_node = tail->next;
			tail->next = NULL;
			// push to heap
			if (next_node != NULL) {
				heap.push(next_node);
			}
		}
		return head;
	}
};

//int main()
//{
//	ListNode* l1 = new ListNode(1);
//	ListNode* p = l1;
//	p->next = new ListNode(4);
//	p = p->next;
//	p->next = new ListNode(5);
//
//	ListNode* l2 = new ListNode(1);
//	p = l2;
//	p->next = new ListNode(3);
//	p = p->next;
//	p->next = new ListNode(4);
//
//	ListNode* l3 = new ListNode(2);
//	p = l3;
//	p->next = new ListNode(6);
//
//	vector<ListNode*> lists{ l1, l2, l3 };
//	Solution* sol = new Solution();
//	ListNode* res = sol->mergeLists(lists);
//	p = res;
//	while (p->next != NULL)
//	{
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << p->val;
//	return 0;
//}
