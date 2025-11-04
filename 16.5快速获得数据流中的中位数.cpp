//#include<iostream>
//#include<queue>
//#include<cmath>
//using namespace std;
//class MedianFinder {
//public:
//	priority_queue<int> maxHeap;
//	priority_queue<int, vector<int>, greater<int>> minHeap;
//	void balance() {
//		if (abs((int)maxHeap.size() - (int)minHeap.size()) == 2) {
//			if (maxHeap.size() > minHeap.size()) {
//				minHeap.push(maxHeap.top());
//				maxHeap.pop();
//			}
//			else {
//				maxHeap.push(minHeap.top());
//				minHeap.pop();
//			}
//		}
//	}
//	MedianFinder() {}
//	void addNum(int num) {
//		if (maxHeap.empty()||num <= maxHeap.top()) maxHeap.push(num);
//		else minHeap.push(num);
//		balance();
//	}
//	double findMedian() {
//		int sum = maxHeap.size() + minHeap.size();
//		if (sum % 2 == 0) return (maxHeap.top() + minHeap.top()) / 2.0;
//		else {
//			if (maxHeap.size() > minHeap.size()) return maxHeap.top();
//			else return minHeap.top();
//		}
//	}
//};