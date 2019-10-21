/* 二叉树的最近公共祖先 */
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 边界条件
		if (root == NULL) return NULL;
		// 如果root是pq之一，返回root
		if (root == p || root == q) return root;

		// 递归左右两边
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// 返回结果
		if (left == NULL) return left;
		if (right == NULL) return right;

		return root;
	}
};

//int main()
//{
//	vector<int> order = { 3,5,1,6,2,0,8,-1,-1,7,4 };
//	TreeNode * root = NULL;
//	TreeNode *p = NULL, *q = NULL;
//
//	// 借助队列创建完全二叉树
//	queue<TreeNode*> que;
//	for (int i = 0; i < order.size(); i++) {
//		TreeNode * node = new TreeNode(order[i]);
//		if (node->val == 5) p = node;
//		if (node->val == 1) q = node;
//
//		if (root == NULL) {
//			root = node;
//			que.push(root);
//		}
//		else {
//			TreeNode* t = que.front();
//			if (t->left == NULL) {
//				t->left = node;
//				que.push(t->left);
//			}
//			else {
//				// 左儿子非空，右儿子空
//				t->right = node;
//				que.push(t->right);
//				que.pop();
//			}
//		}
//	}
//
//	Solution sol = Solution();
//	TreeNode * res = sol.lowestCommonAncestor(root, p, q);
//	cout << res->val << endl;
//
//	return 0;
//}
