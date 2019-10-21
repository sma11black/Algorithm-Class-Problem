/* 二叉查找树中第k小的元素 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int kthSmallest(TreeNode* root, int k)
	{
		vector<int> record;
		stack<TreeNode*> s;
		TreeNode* p = root;

		s.push(p);
		p = p->left;

		while (!s.empty())
		{
			if (p != nullptr) {
				s.push(p);
				p = p->left;
			}
			else {
				TreeNode* top = s.top();
				s.pop();
				record.push_back(top->val);
				p = top->right;
			}
		}
		return record[k - 1];
	}
};

//int main()
//{
//	TreeNode* root = new TreeNode(8);
//	TreeNode* p = root;
//	p->left = new TreeNode(3);
//	p->right = new TreeNode(9);
//	p = p->left;
//	p->left = new TreeNode(1);
//	p->right = new TreeNode(7);
//
//	int k = 3;
//
//	Solution* sol = new Solution();
//	cout << sol->kthSmallest(root, k);
//
//	return 0;
//}