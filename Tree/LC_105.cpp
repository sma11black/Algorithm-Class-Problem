/* ��ǰ��������������й�������� */
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
		// �߽�����
		if (lpre > rpre) return NULL;
		if (lpre == rpre) return new TreeNode(preorder[lpre]);

		// ǰ��ĵ�һ��ֵ�Ǹ��ڵ�
		TreeNode* root = new TreeNode(preorder[lpre]);
		// ȡ������ĸ��ڵ�
		int idx = m[root->val];

		// �ݹ���������
		TreeNode* left_tree = dfs(preorder, lpre + 1, lpre + (idx - lin), inorder, lin, idx - 1, m);
		TreeNode* right_tree = dfs(preorder, lpre + (idx - lin) + 1, rpre, inorder, idx + 1, rin, m);

		// ���ظ��ڵ�
		root->left = left_tree;
		root->right = right_tree;

		return root;
	}

public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		// �߽�����
		if (preorder.size() == 0) return NULL;

		// ��¼����ÿ��ֵ���±�
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
