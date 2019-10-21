/* 反转链表 */
#include <iostream>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* 递归解法 */
class SolutionRecursive
{
public:
	ListNode * reverseList(ListNode* head) {
		// 边界条件
		if (head == NULL) return head;
		if (head->next == NULL) return head;

		// 取出下一个结点
		ListNode* next_node = head->next;
		// 反转下一个结点开始的链表
		ListNode* res = reverseList(next_node);
		// 将头结点连回去
		next_node->next = head;
		head->next = NULL;

		return res;
	}
};

/* 非递归解法 */
class SolutionNonRecursive
{
public:
	ListNode * reverseList(ListNode* head) {
		// 边界条件
		if (head == NULL) return head;
		if (head->next == NULL) return head;

		// 新建空结果链表
		ListNode* res = NULL;
		while (head) {
			if (res == NULL) {
				// 如果结果链表为空，结果链表等于头结点
				res = head;
				head = head->next;
				res->next = NULL;
			}
			else {
				// 如果结果链表不为空
				// 先记录下一个结点
				ListNode* tmp = head->next;
				// 将当前head连接到结果链表
				head->next = res;
				// 更新结果链表头结点
				res = head;
				// 更新head
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
//			ungetc(c, stdin);  // 如果字符c不是空格，就要将c字符还回到流中，不然造成数据读取错误
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
