//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int value):val(value),next(nullptr){}
//};
//class Solution {
//public:
//	void reverse(ListNode* s, ListNode* e) {
//		e = e->next;
//		ListNode* pre = nullptr;
//		ListNode* cur = s;
//		ListNode* next = nullptr;
//		while (cur != e) {
//			next = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//		}
//		s->next = e;
//	}
//	ListNode* ListEnd(ListNode* p, int k) {
//		while (--k != 0 && p != nullptr) {
//			p = p->next;
//		}
//		return p;
//	}
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode* start = head;
//		ListNode* end =ListEnd(start,k);
//		if (end == nullptr) return head;
//		head = end;
//		reverse(start, end);
//		ListNode* lastListEnd = start;
//		while (lastListEnd != nullptr) {
//			start = lastListEnd->next;
//			end = ListEnd(start, k);
//			if (end == nullptr) return head;
//			reverse(start, end);
//			lastListEnd->next = end;
//			lastListEnd = start;
//		}
//		return head;
//
//	}
//	
//
//};