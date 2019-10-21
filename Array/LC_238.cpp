/* 除自身以外数组的乘积 */
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int> nums) {
		int n = nums.size();
		vector<int> left_product(n, 1);

		// 计算左积数组
		int last_product = 1;
		for (int i = 0; i < n; i++) {
			last_product *= nums[i];
			left_product[i] = last_product;
		}

		// 反向遍历，last_product维护右积数组结果
		last_product = 1;
		for (int i = n - 1; i > 0; i--) {
			left_product[i] = last_product * left_product[i - 1];
			last_product *= nums[i];
		}
		left_product[0] = last_product;

		return left_product;
	}
};

//int main()
//{
//	Solution sol = Solution();
//	vector<int> nums = { 1,2,3,4 };
//	vector<int> res;
//	res = sol.productExceptSelf(nums);
//	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
//		cout << *iter << " ";
//	}
//	cout << endl;
//	return 0;
//}
