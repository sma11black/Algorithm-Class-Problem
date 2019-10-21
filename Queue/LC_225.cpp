/* �ö���ʵ��ջ */
#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
	queue<int> q1;
	queue<int> q2;
public:
	/* Initialize your data structure here. */
	MyStack() {

	}

	/* Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/* Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = top();
		q1.pop();

		// ����q1, q2
		swap(q1, q2);

		return res;

	}

	/* Get the top element. */
	int top() {
		// �Ȱ�q1ֻ����һ��Ԫ��
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// q1���׵õ�top()
		return q1.front();
	}

	/* Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
};

//int main()
//{
//	int x = 1;
//	MyStack* obj = new MyStack();
//	obj->push(x);
//	obj->push(x+1);
//	int param_2 = obj->pop();
//	int param_3 = obj->top();
//	bool param_4 = obj->empty();
//
//	cout << param_2 << " " << param_3 << " " << param_4 << endl;
//
//    return 0;
//}
