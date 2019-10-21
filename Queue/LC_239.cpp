/* �����������ֵ */
#include <vector>
#include <deque>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// <ʱ���, ����>
		deque< tuple<int, int> > q;
		int len = nums.size();
		vector<int> res;

		for (int i = 0; i < len; i++) {
			// �ж϶����Ƿ�Ӧ�ó���
			if (!q.empty() && get<0>(q.front()) == i - k) {
				q.pop_front();
			}
			// �ж϶�β�Ƿ�Ӧ�ó���
			while (!q.empty() && nums[i] >= get<1>(q.back())) {
				q.pop_back();
			}
			q.push_back(tuple<int, int>(i, nums[i]));

			res.push_back(get<1>(q.front()));
		}

		// ���ֻ����k-1����ģ�ǰ��Ľ��������k����
		return vector<int>(res.begin() + k - 1, res.end());
	}
};

//int main()
//{
//	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
//	int k = 3;
//	Solution* sol = new Solution();
//	vector<int> res = sol->maxSlidingWindow(nums, k);
//	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
//		cout << *iter << " ";
//	}
//	cout << endl;
//	return 0;
//}
