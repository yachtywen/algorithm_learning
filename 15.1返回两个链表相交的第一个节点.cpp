//#include<iostream>
//using namespace std;
//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int v):val(v),next(nullptr){}
//};
//class Solution {
//public:
//	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//		/*ListNode* p1 = headA;
//		ListNode* p2 = headB;
//		int lenA=0, lenB=0;
//		while (p1->next) {
//			lenA++;
//			p1 = p1->next;
//		}
//		while (p2->next) {
//			lenB++;
//			p2 = p2->next;
//		}
//		if (p1 != p2) return nullptr;
//		p1 = lenA > lenB ? headA : headB;
//		p2 = (p1 == headA) ? headB : headA;
//		int diff = abs(lenA - lenB);
//		while (diff > 0) {
//			diff--;
//			p1 = p1->next;
//		}
//		while (p1!=p2) {
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//		return p1;*/
//	}
//};