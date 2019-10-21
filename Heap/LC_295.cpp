/* 数据流的中位数 */
#include <queue>
#include <iostream>

using namespace std;

class MedianFinder
{
	priority_queue<int> lo;	// max heap
							// std::priority_queue<T, std::vector<T>, cmp>
	priority_queue<int, vector<int>, greater<int> > hi;	// min heap
public:
	/* initialize data structure. */
	MedianFinder() {}

	void addNum(int num) {
		lo.push(num);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}

	double findMedian() {
		return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
	}
};

//int main()
//{
//	MedianFinder* obj = new MedianFinder();
//	obj->addNum(1);
//	obj->addNum(2);
//	cout << obj->findMedian() << endl;
//	obj->addNum(3);
//	cout << obj->findMedian() << endl;
//
//	return 0;
//}
