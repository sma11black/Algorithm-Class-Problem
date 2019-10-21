/* 滑动窗口最大值 */
#include <vector>
#include <deque>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// <时间戳, 数字>
		deque< tuple<int, int> > q;
		int len = nums.size();
		vector<int> res;

		for (int i = 0; i < len; i++) {
			// 判断队首是否应该出队
			if (!q.empty() && get<0>(q.front()) == i - k) {
				q.pop_front();
			}
			// 判断队尾是否应该出队
			while (!q.empty() && nums[i] >= get<1>(q.back())) {
				q.pop_back();
			}
			q.push_back(tuple<int, int>(i, nums[i]));

			res.push_back(get<1>(q.front()));
		}

		// 结果只保留k-1往后的，前面的结果都不到k个数
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
