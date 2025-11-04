//#include<iostream>
//#include<unordered_map>
//using namespace std;
//class LRUCache {
//private:
//	struct DoubleNode {
//		int val;
//		int key;
//		DoubleNode* last;
//		DoubleNode* next;
//		DoubleNode(int k, int v) :key(k), val(v), last(nullptr), next(nullptr){}
//	};
//	class DoubleList {
//	public:
//		DoubleNode* head;
//		DoubleNode* tail;
//		DoubleList():head(nullptr),tail(nullptr){}
//		void addNode(DoubleNode* newNode) {
//			if (!newNode) return;
//			if (!head) head = tail=newNode;
//			else {
//				tail->next = newNode;
//				newNode->last = tail;
//				tail = newNode;
//			}
//
//		}
//		void moveNodeToTail(DoubleNode* node) {
//			if (tail == node) return;
//			if (head == node) {
//				head = node->next;
//				head->last = nullptr;
//			}
//			else {
//				node->last->next = node->next;
//				node->next->last = node->last;
//			}
//			node->last = tail;
//			node->next = nullptr;
//			tail->next = node;
//			tail = node;
//		}
//		DoubleNode* removeHead() {
//			if (head == nullptr) return nullptr;
//			DoubleNode* ans = head;
//			if (head == tail) head = tail = nullptr;
//			else {
//				head = head->next;
//				head->last = nullptr;
//				ans->next = nullptr;
//			}
//			return ans;
//		}
//	};
//	unordered_map<int, DoubleNode*> keyNodeMap;
//	DoubleList nodeList;
//	int capacity;
//public:
//	LRUCache(int cap):capacity(cap){}
//	int get(int key) {
//		if (keyNodeMap.count(key)) {
//			DoubleNode* ans = keyNodeMap[key];
//			nodeList.moveNodeToTail(ans);
//			return ans->val;
//		}
//		return -1;
//	}
//	void put(int key, int value) {
//		if (keyNodeMap.count(key)) {
//			DoubleNode* node = keyNodeMap[key];
//			node->val = value;
//			nodeList.moveNodeToTail(node);
//		}
//		else {
//			if (keyNodeMap.size() == capacity) {
//				DoubleNode* removed = nodeList.removeHead();
//				keyNodeMap.erase(removed->key);
//				delete removed;
//			}
//			DoubleNode* newNode = new DoubleNode(key, value);
//			keyNodeMap[key] = newNode;
//			nodeList.addNode(newNode);
//		}
//	}
//};