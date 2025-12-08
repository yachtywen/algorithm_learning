#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())return 0;
        unordered_set<string>smallLevel;
        unordered_set<string>bigLevel;
        unordered_set<string>nextLevel;
        smallLevel.insert(beginWord);
        bigLevel.insert(endWord);
        for (int len = 2; !smallLevel.empty(); len++) {
            for (const string& w : smallLevel) {
                string word = w;
                for (int j = 0; j < word.length(); j++) {
                    char old = word[j];
                    for (char change = 'a'; change <= 'z'; change++) {
                        if (change == old)continue;
                        word[j] = change;
                        if (bigLevel.find(word) != bigLevel.end()) {
                            return len;
                        }if (dict.find(word) != dict.end()) {
                            nextLevel.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = old;
                }
            }
            if (nextLevel.size() <= bigLevel.size()) {
                smallLevel = nextLevel;
            }
            else {
                smallLevel = bigLevel;
                bigLevel = nextLevel;
            }
            nextLevel.clear();
        }
        return 0;
    }
};