/* 从前序与中序遍历序列构造二叉树 */
#include <vector>
#include <map>
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
private:
	TreeNode * dfs(vector<int>& preorder, int lpre, int rpre, vector<int>& inorder, int lin, int rin, map<int, int>& m) {
		// 边界条件
		if (lpre > rpre) return NULL;
		if (lpre == rpre) return new TreeNode(preorder[lpre]);

		// 前序的第一个值是根节点
		TreeNode* root = new TreeNode(preorder[lpre]);
		// 取出中序的根节点
		int idx = m[root->val];

		// 递归左右子树
		TreeNode* left_tree = dfs(preorder, lpre + 1, lpre + (idx - lin), inorder, lin, idx - 1, m);
		TreeNode* right_tree = dfs(preorder, lpre + (idx - lin) + 1, rpre, inorder, idx + 1, rin, m);

		// 连回根节点
		root->left = left_tree;
		root->right = right_tree;

		return root;
	}

public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		// 边界条件
		if (preorder.size() == 0) return NULL;

		// 记录中序每个值的下标
		map<int, int> m;
		for (int i = 0; i < inorder.size(); i++) {
			m[inorder[i]] = i;
		}
		return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
	}

};

//int main()
//{
//	vector<int> preorder = { 3,9,20,15,7 };
//	vector<int> inorder = { 9,3,15,20,7 };
//
//	Solution sol = Solution();
//	TreeNode * res = sol.buildTree(preorder, inorder);
//
//    return 0;
//}
