//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x):val(x),next(nullptr){}
//};
//class Solution {
//public:
//	ListNode* detectCycle(ListNode* head) {
//		if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
//			return nullptr;
//		}
//		ListNode* fast = head->next->next;
//		ListNode* slow = head->next;
//		while (fast != slow) {
//			if (fast->next == nullptr || fast->next->next == nullptr) {
//				return nullptr;
//			}
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		fast = head;
//		while (fast != slow) {
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};