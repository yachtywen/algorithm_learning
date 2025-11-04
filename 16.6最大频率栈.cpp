//#include<iostream>
//#include<unordered_map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class FreqStack {
//public:
//	int topTimes;
//	unordered_map<int, vector<int>> cntValues;
//	unordered_map<int, int> valueTimes;
//    FreqStack() {
//        topTimes = 0;
//    }
//
//    void push(int val) {
//        valueTimes[val]= valueTimes[val]+1;
//        int curTopTimes = valueTimes[val];
//        if (cntValues.find(curTopTimes) == cntValues.end()) {
//            cntValues[curTopTimes] = vector<int>();
//        }
//        cntValues[curTopTimes].push_back(val);
//        topTimes = max(topTimes, curTopTimes);
//    }
//
//    int pop() {
//        int ans = cntValues[topTimes].back();
//        cntValues[topTimes].pop_back();
//        if (cntValues[topTimes].empty()) {
//            cntValues.erase(topTimes);
//            topTimes--;
//        }
//        if (valueTimes[ans] == 1) {
//            valueTimes.erase(ans);
//        }
//        else {
//            valueTimes[ans]--;
//        }
//        return ans;
//    }
//};