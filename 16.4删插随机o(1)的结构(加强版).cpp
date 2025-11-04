//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//#include <cstdlib>   
//#include <ctime>     
//using namespace std;
//class RandomizedCollection {
//public:
//    unordered_map<int, unordered_set<int>> mp; 
//    vector<int> arr; 
//    bool insert(int val) {
//        arr.push_back(val);
//        mp[val].insert(arr.size() - 1);
//        return mp[val].size() == 1;
//    }
//    bool remove(int val) {
//        if (!mp.count(val)) return false;
//        //mp[val].begin()是迭代器，前面加*表示取值
//        int idx = *mp[val].begin();
//        int lastVal = arr.back();
//        mp[val].erase(idx);
//        if (idx != arr.size() - 1) {
//            arr[idx] = lastVal;
//            mp[lastVal].insert(idx);
//            //arr.size()-1就是索引值
//            mp[lastVal].erase(arr.size() - 1);
//        }
//        arr.pop_back();
//        if (mp[val].empty()) mp.erase(val);
//        return true;
//    }
//    int getRandom() {
//        if (arr.empty()) return-1;
//        int randomIndex = rand() % arr.size();
//        return arr[randomIndex];
//    }
//};
