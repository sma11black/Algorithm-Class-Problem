/* 简单计算器 */
#include <string>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
	int calculate(string s) {

		// 符号优先级
		map<char, int> rank = { { '+', 1 },{ '-', 1 },{ '(', 100 },{ ')', -100 } };
		// 定义数字栈与符号栈,符号栈是单调栈
		stack<int> num_stack;
		stack<char> op_stack;

		for (int i = 0; i < s.size(); i++) {
			// 跳过空格
			if (s[i] == ' ') continue;
			// 数值转换
			if (s[i] >= '0' && s[i] <= '9') {
				if (i != 0 && s[i - 1] >= '0' && s[i - 1] <= '9') {
					num_stack.top() = num_stack.top() * 10 + s[i] - '0';
				}
				else {
					num_stack.push(s[i] - '0');
				}
			}
			// 处理运算符号
			else if (s[i] == '+' || s[i] == '-') {
				while (op_stack.size() != 0 && rank[s[i]] >= rank[op_stack.top()]) {
					calUnit(op_stack, num_stack);
				}
				op_stack.push(s[i]);
			}
			else if (s[i] == '(') {
				op_stack.push(s[i]);
			}
			else if (s[i] == ')') {
				while (op_stack.top() != '(') {
					calUnit(op_stack, num_stack);
				}
				op_stack.pop();
			}
		}
		while (op_stack.size() != 0) {
			calUnit(op_stack, num_stack);
		}
		return num_stack.top();
	}

private:
	void calUnit(stack<char>& op_stack, stack<int>& num_stack) {
		char op = op_stack.top(); op_stack.pop();
		int a = num_stack.top(); num_stack.pop();
		int b = num_stack.top(); num_stack.pop();
		int res = 0;
		if (op == '+') {
			res = b + a;
		}
		else if (op == '-') {
			res = b - a;
		}
		num_stack.push(res);
	}
};

//int main()
//{
//	Solution sol = Solution();
//	string s1 = "1 + 1";
//	string s2 = " 2-1 + 2 ";
//	string s3 = "(1+(4+5+2)-3)+(6+8)";
//	int res;
//	res = sol.calculate(s1);
//	cout << res << endl;
//	res = sol.calculate(s2);
//	cout << res << endl;
//	res = sol.calculate(s3);
//	cout << res << endl;
//    return 0;
//}
