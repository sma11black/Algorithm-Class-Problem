/* 找到数组左边的重复数 */
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> findLeftRepeatNum(vector<int>& nums) {
		int n = nums.size();

		map<int, int> m;
		vector<int> res(n, -1);
		for (int i = 0; i < n; i++) {
			if (m.count(nums[i])) {
				res[i] = m[nums[i]];
			}
			else {
				m[nums[i]] = i;
				res[i] = -1;
			}
		}
		return res;
	}
};

//int main()
//{
//	Solution sol = Solution();
//	vector<int> nums = { 1, 3, 1, 2, 1 };
//	vector<int> res;
//	res = sol.findLeftRepeatNum(nums);
//	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
//		cout << *iter << " ";
//	}
//	cout << endl;
//	return 0;
//}
