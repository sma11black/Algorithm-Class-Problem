/* 132模式 */
#include <vector>
#include <stack>
#include <tuple> //考虑使用pair替换
#include <iostream>

using namespace std;

class Solution
{
public:
	bool find132Pattern(vector<int>& nums) {
		// 边界条件
		if (nums.size() < 3) return false;

		stack< tuple<int, int> > stack;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (stack.empty() || nums[i] < get<0>(stack.top())) {
				stack.push(tuple<int, int>(nums[i], nums[i]));
			}
			else {
				int cur_min = get<0>(stack.top());
				while (!stack.empty() && nums[i] >= get<1>(stack.top())) {
					stack.pop();
				}

				if (!stack.empty() && nums[i] > get<0>(stack.top()) && nums[i] < get<1>(stack.top())) {
					return true;
				}
				stack.push(tuple<int, int>(cur_min, nums[i]));
			}
		}
		return false;
	}
};

//int main()
//{
//	Solution sol = Solution();
//	//vector<int> nums = { 1, 2, 3, 4 };
//	//vector<int> nums = { 3, 1, 4, 2 };
//	vector<int> nums = { -1, 3, 2, 0 };
//	bool res = sol.find132Pattern(nums);
//	cout << res << endl;
//	return 0;
//}
