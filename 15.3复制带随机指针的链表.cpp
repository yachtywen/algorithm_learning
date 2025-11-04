//#include<iostream>
//using namespace std;
//struct Node {
//    int val;
//    Node* next;
//    Node* random;
//    Node(int v) : val(v), next(nullptr), random(nullptr) {}
//};
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr) return nullptr;
//        Node* cur = head;
//        Node* next = nullptr;
//        //在原链表之中插入节点
//        while (cur != nullptr) {
//            next = cur->next;
//            cur->next = new Node(cur->val);
//            cur->next->next = next;
//            cur = next;
//        }
//        //复制random指针
//        cur = head;
//        next = head->next;
//        while (cur != nullptr) {
//            next->random = (cur->random == nullptr) ? nullptr : cur->random->next;
//            cur = next->next;
//            if(cur!=nullptr) next = cur->next;
//        }
//        //将从原链表中克隆的链表剥离
//        Node* pre;
//        Node* ans = head->next;
//        cur = head;
//        while (cur != nullptr) {
//            next = cur->next->next;
//            pre = cur->next;
//            cur->next = next;
//            pre->next = (next == nullptr) ? nullptr : next->next;
//            cur = next;
//        }
//        return ans;
//    }
//};