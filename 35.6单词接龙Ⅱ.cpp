#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<deque>
using namespace std;
class Solution {
public:
    vector<vector<string>>ans;
    unordered_map<string, vector<string>>graph;
    deque<string>path;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())return ans;
        if (bfs(beginWord, endWord, dict)) {
            dfs(endWord, beginWord);
        }
        return ans;
    }
    bool bfs(string& begin, string& end, unordered_set<string>& dict) {
        unordered_set<string>curLevel;
        curLevel.insert(begin);
        bool find = false;
        while (!curLevel.empty()) {
            for (const string& word : curLevel) {
                dict.erase(word);
            }
            unordered_set<string>nextLevel;
            for (const string& word : curLevel) {
                string str = word;
                for (int i = 0; i < str.size(); i++) {
                    char old = str[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == old)continue;
                        str[i] = ch;
                        if (dict.count(str)) {
                            if (str == end) {
                                find = true;
                            }
                            graph[str].push_back(word);
                            nextLevel.insert(str);
                        }
                    }
                    str[i] = old;
                }
            }
            if (find)return true;
            curLevel = nextLevel;
        }
        return false;
    }
    void dfs(string& word, string& aim) {
        path.push_front(word);
        if (word == aim) {
            ans.push_back(vector<string>(path.begin(), path.end()));
        }
        else if (graph.count(word)) {
            for (string& next : graph[word]) {
                dfs(next, aim);
            }
        }
        path.pop_front();
    }
};