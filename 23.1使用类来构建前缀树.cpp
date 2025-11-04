//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
////用类构建前缀树
//class TrieTree01 {
//public:
//	struct TrieNode {
//		int pass;
//		int end;
//		//26个字母,故最多26个分支
//		TrieNode* nexts[26];
//		TrieNode() {
//			pass = 0;
//			end = 0;
//			for (int i = 0; i < 26; i++) {
//				nexts[i] = nullptr;
//			}
//		}
//     };
//	TrieNode* root;
//	TrieTree01() {
//		root = new TrieNode();
//	}
//	void insert(string& word) {
//		TrieNode* node = root;
//		node->pass++;
//		for (int i = 0; i < word.size(); i++) {
//			int path = word[i] - 'a';
//			if (node->nexts[path] == nullptr) {
//				node->nexts[path] == new TrieNode();
//			}
//			node = node->nexts[path];
//			node->pass++;
//		}
//		node->end++;
//	}
//	void erase(string word) {
//		if (search(word) > 0) {
//			TrieNode* node = root;
//			node->pass--;
//			for (int i = 0; i < word.size(); i++) {
//				int path = word[i] - 'a';
//				TrieNode* next = node->nexts[path];
//				if (--(next->pass) == 0) {
//					node->nexts[path] = nullptr;
//				}
//				node = next;
//			}
//			node->end--;
//		}
//	}
//	int search(string word) {
//		TrieNode* node = root;
//		for (int i = 0; i < word.empty(); i++) {
//			int path = word[i] - 'a';
//			if (node->nexts[path] == nullptr) {
//				return 0;
//			}
//			node=node->nexts[path];
//		}
//		return node->end;
//	}
//	int prefixNumber(string pre) {
//		TrieNode* node = root;
//		for (int i = 0; i < pre.size(); i++) {
//			int path = pre[i] - 'a';
//			if (node->nexts[path] == nullptr) {
//				return 0;
//			}
//			node = node->nexts[path];
//		}
//		return node->pass;
//	}
//};
