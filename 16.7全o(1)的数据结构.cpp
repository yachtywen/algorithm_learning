//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//#include <string>
//using namespace std;
//class AllOne {
//public:
//	struct Bucket {
//		unordered_set<string> set;
//		int cnt;
//		Bucket* last;
//		Bucket* next;
//		Bucket(string& s, int c) {
//			set.insert(s);
//			cnt = c;
//			last = nullptr;
//			next = nullptr;
//		}
//		Bucket(int c) {
//			cnt = c;
//			last = nullptr;
//			next = nullptr;
//		}
//	};
//	Bucket* head;
//	Bucket* tail;
//	unordered_map<string, Bucket*> mp;
//	void insert(Bucket* cur, Bucket* pos) {
//		pos->next = cur->next;
//		pos->last = cur;
//		cur->next->last = pos;
//		cur->next = pos;
//	}
//	void remove(Bucket* cur) {
//		cur->last->next = cur->next;
//		cur->next->last = cur->last;
//		delete cur;
//	}
//	AllOne() {
//		head = new Bucket(0);
//		tail = new Bucket(INT_MAX);
//		head->next = tail;
//		tail->last = head;
//	}
//	void inc(string key) {
//		if (!mp.count(key)) {
//			if (head->next->cnt == 1) {
//				mp[key] = head->next;
//				head->next->set.insert(key);
//			}
//			else {
//				Bucket* newBucket = new Bucket(key, 1);
//				insert(head, newBucket);
//				mp[key] = newBucket;
//			}
//		}
//		else {
//			Bucket* bucket = mp[key];
//			if (bucket->next->cnt == bucket->cnt + 1) {
//				bucket->next->set.insert(key);
//				mp[key] = bucket->next;
//			}
//			else {
//				Bucket* newBucket = new Bucket(key,bucket->cnt+1);
//				insert(bucket, newBucket);
//				mp[key] = newBucket;
//			}
//			bucket->set.erase(key);
//			if (bucket->set.empty()) remove(bucket);
//		}
//	}
//	void dec(string key) {
//		Bucket* bucket = mp[key];
//		if (bucket->cnt == 1)mp.erase(key);
//		else {
//			if (bucket->last->cnt == bucket->cnt - 1) {
//				mp[key] = bucket->last;
//				bucket->last->set.insert(key);
//			}
//			else {
//				Bucket* newBucket = new Bucket(key, bucket->cnt - 1);
//				insert(bucket->last, newBucket);
//				mp[key] = newBucket;
//			}
//		}
//		bucket->set.erase(key);
//		if (bucket->set.empty()) remove(bucket);
//	}
//
//	string getMaxKey() {
//		if (tail->last == head) return "";
//		return *(tail->last->set.begin());
//	}
//
//	string getMinKey() {
//		if (head->next == tail) return "";
//		//哈希set的begin函数返回的是一个迭代器故要加*来取值
//		return *(head->next->set.begin());
//	}
//};