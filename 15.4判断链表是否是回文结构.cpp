//#include<iostream>
//using namespace std;
//
// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) return true;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while (fast->next != nullptr && fast->next->next != nullptr) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         ListNode* pre = nullptr;
//         ListNode* next = nullptr;
//         ListNode* cur = slow->next;
//         slow->next = nullptr;
//         while (cur != nullptr) {
//             next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         ListNode* left = head;
//         ListNode* right = pre;
//         while (left != nullptr && right != nullptr) {
//             if (left->val != right->val) return false;
//             left = left->next;
//             right = right->next;
//         }
//         cur = pre->next;
//         pre->next = nullptr;
//         while (cur != nullptr) {
//             next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         return true;
//     }
// };