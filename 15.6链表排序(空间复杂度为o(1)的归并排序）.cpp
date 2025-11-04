//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x):val(x),next(nullptr){}
//};
//class Solution {
//public:
//	ListNode* start=nullptr;
//	ListNode* end=nullptr;
//	//找到end节点
//	ListNode* findEnd(ListNode* s,int k){
//		while (s != nullptr && s->next != nullptr && --k > 0) {
//			s = s->next;
//		 }
//		return s;
//	}
//		//将两段变有序
//	void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2) {
//		ListNode* pre = nullptr;
//		if (l1->val <= l2->val) {
//			start = l1;
//			pre = l1;
//			l1 = l1->next;
//		}
//		else {
//			start = l2;
//			pre = l2;
//			l2 = l2->next;
//		}
//		while (l1 != nullptr && l2 != nullptr) {
//			if (l1->val <= l2->val) {
//				pre->next = l1;
//				pre = l1;
//				l1 = l1->next;
//			}
//			else {
//				pre->next = l2;
//				pre = l2;
//				l2 = l2->next;
//			}
//		}
//		if (l1 != nullptr) {
//			pre->next=l1;
//			end = r1;
//		}
//		else {
//			pre->next = l2;
//			end = r2;
//		}
//	}
//	ListNode* sortList(ListNode* head) {
//		if (!head || !head->next) return head;
//		int n = 0;
//		ListNode* cur = head;
//		while (cur) {
//			n++;
//			cur = cur->next;
//		}
//		for (int step = 1; step < n; step *= 2) {
//			ListNode* l1 = head;
//			ListNode* r1 = findEnd(l1, step);
//			if (!r1) break;
//			ListNode* l2 = r1->next;
//			if (!l2) break;
//			ListNode* r2 = findEnd(l2, step);
//			ListNode* next = r2 ? r2->next : nullptr;
//			r1->next = nullptr;
//			if (r2) r2->next = nullptr;
//			merge(l1, r1, l2, r2);
//			head = start;
//			ListNode* lastTeamEnd = end;
//			while (next) {
//				l1 = next;
//				r1 = findEnd(l1, step);
//				if (!r1) {
//					lastTeamEnd->next = l1;
//					break;
//				}
//				l2 = r1->next;
//				if (!l2) {
//					lastTeamEnd->next = l1;
//					break;
//				}
//				r2 = findEnd(l2, step);
//				next = r2 ? r2->next : nullptr;
//				r1->next = nullptr;
//				if (r2) r2->next = nullptr;
//				merge(l1, r1, l2, r2);
//				lastTeamEnd->next = start;
//				lastTeamEnd = end;
//			}
//		}
//		return head;
//	}
//	
//};