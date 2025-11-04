//#include"iostream"
//using namespace std;
//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int value) :val(value), next(nullptr) {}
//	ListNode(int value, ListNode* nextNode) :val(value), next(nextNode) {}
//};
//class Solution {
//public:
//	static ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
//		ListNode* ans = nullptr;
//		ListNode* cur = nullptr;
//		int carry = 0;
//		while (h1 != nullptr || h2 != nullptr) {
//			int sum = (h1 ? h1->val : 0) + (h2 ? h2->val : 0) + carry;
//			int val = sum % 10;
//			carry = sum / 10;
//			if (!ans) {
//				ans = new ListNode(val);
//				cur = ans;
//			}else {
//				cur->next = new ListNode(val);
//				cur = cur->next;
//			}
//			if (h1) h1 = h1->next;
//			if (h2) h2 = h2->next;
//		}
//		if (carry) {
//			cur->next = new ListNode(1);
//		}
//		return ans;
//	}
//};
//void PrintList(ListNode* head) {
//	while (head) {
//		cout << head->val << " ";
//		head = head->next;
//	}
//	cout << endl;
//}
//int main() {
//	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
//	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
//	ListNode* result = Solution::addTwoNumbers(l1, l2);
//	PrintList(result);
//	return 0;
//}