//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//    unordered_map<string, int> m;
//
//    // 🟢 1. 插入元素
//    m["apple"] = 3;
//    m.insert({ "banana", 5 });
//    m.emplace("pear", 7);  // 更高效
//
//    // 🟢 2. 访问元素
//    cout << m["apple"] << endl;       // 输出 3
//    cout << m.at("banana") << endl;   // 输出 5
//    // cout << m.at("orange") << endl; // 若不存在会抛异常
//
//    // 🟢 3. 判断键是否存在
//    if (m.count("pear")) cout << "有 pear\n";
//    if (m.find("banana") != m.end()) cout << "找到 banana\n";
//
//    // 🟢 4. 删除元素
//    m.erase("apple");   // 按键删除
//    m.clear();          // 清空整个哈希表
//
//    // 🟢 5. 遍历哈希表
//    m = { {"A", 1}, {"B", 2}, {"C", 3} };
//    for (auto& p : m)
//        cout << p.first << " -> " << p.second << endl;
//
//    // 🟢 6. 其他函数
//    cout << "size = " << m.size() << endl;
//    cout << "empty = " << m.empty() << endl;
//}
