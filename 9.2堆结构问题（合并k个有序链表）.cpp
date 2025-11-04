//#include<iostream>
//#include<vector>
//#include<queue>
//#include<functional>
//using namespace std;
////题目要求：根据从小到大合并k个顺序链表
//class ListNode {
//public:
//	ListNode* next;
//	int val;
//	ListNode(int x):val(x),next(nullptr){}
//};
////比较器，将大根堆变成小根堆
//
//class Compare {
//public:
//	bool operator()(ListNode* a, ListNode* b) {
//		//返回true是对于priority_queue表示a的优先级小于b的优先级
//		return a->val > b->val;
//	}
//};
//
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& arr) {
//		//申请了一个小根堆 heap
//		priority_queue<ListNode*, vector<ListNode*>,Compare> heap;
//
//		for (int i = 0; i < arr.size(); i++) {
//			ListNode* h = arr[i];
//			if (h != nullptr) heap.push(h);
//		}
//		if (heap.empty()) {
//			return nullptr;
//		}
//		ListNode* head =heap.top();
//		heap.pop();
//		ListNode* pre = head;
//		if (pre->next != nullptr)heap.push(pre->next);
//		while (!heap.empty()) {
//			ListNode* cur = heap.top();
//			heap.pop();
//			pre->next = cur;
//			pre = cur;
//			if (cur->next != nullptr) heap.push(cur->next);
//		}
//		return head;
//	}
//};