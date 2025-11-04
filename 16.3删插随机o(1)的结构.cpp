//#include<iostream>
//#include<unordered_map>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//class RandomizedSet {
//private:
//	unordered_map<int, int> map;
//	vector<int> arr;
//public:
//	RandomizedSet() {
//		srand((unsigned)time(nullptr)); 
//	}
//	bool insert(int val) {
//		if (map.count(val)) {
//			return false;
//		}
//		map[val] = arr.size();
//		arr.push_back(val);
//		return true;
//	}
//	bool remove(int val) {
//		if (!map.count(val)) return false;
//		int value_index = map[val];
//		int end_value = arr.back();
//		arr[value_index] = end_value;
//		map[end_value] = value_index;
//		arr.pop_back();
//		map.erase(val);
//		return true;
//	}
//	int getRandom() {
//		if (arr.empty()) return -1;
//		int idx = rand() % arr.size();
//		return arr[idx];
//	}
//};