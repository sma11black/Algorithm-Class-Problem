/* —∞’“∑®πŸ */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int findJudge(int N, vector<vector<int>>& trust)
	{
		vector<int> inDegree = vector<int>(N, 0);
		vector<int> outDegree = vector<int>(N, 0);
		for (vector<int> edge : trust) {
			outDegree[edge[0]-1]++;
			inDegree[edge[1]-1]++;
		}
		for (int i = 0; i < N; i++) {
			if (inDegree[i] == N - 1 && outDegree[i] == 0)
				return i + 1;
		}
		return -1;
	}
};

int main()
{
	int N = 4;
	vector<vector<int>> trust{ {1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3} };
	Solution* sol = new Solution();

	cout << sol->findJudge(N, trust);

	return 0;
}