/* ������������������� */
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
		// �߽�����
		if (root == NULL) return NULL;
		// ���root��pq֮һ������root
		if (root == p || root == q) return root;

		// �ݹ���������
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// ���ؽ��
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
//	// �������д�����ȫ������
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
//				// ����ӷǿգ��Ҷ��ӿ�
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
