/* ��ת���� */
#include <iostream>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* �ݹ�ⷨ */
class SolutionRecursive
{
public:
	ListNode * reverseList(ListNode* head) {
		// �߽�����
		if (head == NULL) return head;
		if (head->next == NULL) return head;

		// ȡ����һ�����
		ListNode* next_node = head->next;
		// ��ת��һ����㿪ʼ������
		ListNode* res = reverseList(next_node);
		// ��ͷ�������ȥ
		next_node->next = head;
		head->next = NULL;

		return res;
	}
};

/* �ǵݹ�ⷨ */
class SolutionNonRecursive
{
public:
	ListNode * reverseList(ListNode* head) {
		// �߽�����
		if (head == NULL) return head;
		if (head->next == NULL) return head;

		// �½��ս������
		ListNode* res = NULL;
		while (head) {
			if (res == NULL) {
				// ����������Ϊ�գ�����������ͷ���
				res = head;
				head = head->next;
				res->next = NULL;
			}
			else {
				// ����������Ϊ��
				// �ȼ�¼��һ�����
				ListNode* tmp = head->next;
				// ����ǰhead���ӵ��������
				head->next = res;
				// ���½������ͷ���
				res = head;
				// ����head
				head = tmp;
			}
		}

		return res;
	}
};

//int main()
//{
//	ListNode* head = new ListNode(0);
//	ListNode* p = head;
//	char c;
//	while ((c = getchar()) != '\n') {
//		if (c != ' ') {
//			ungetc(c, stdin);  // ����ַ�c���ǿո񣬾�Ҫ��c�ַ����ص����У���Ȼ������ݶ�ȡ����
//			ListNode* node = new ListNode(-1);
//			cin >> node->val;
//			p->next = node;
//			p = node;
//		}
//	}
//	head = head->next;
//	p->next = NULL;
//
//	//SolutionRecursive sol = SolutionRecursive();
//	SolutionNonRecursive sol = SolutionNonRecursive();
//	ListNode* res = sol.reverseList(head);
//	p = res;
//	while(p){
//		cout << p->val << "->";
//		p = p->next;
//	}
//	cout << "NULL" << endl;
//
//    return 0;
//}
