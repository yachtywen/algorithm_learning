#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 10001;
    int tree[MAXN][26];
    int passCnt[MAXN];
    string endWord[MAXN];
    int cnt = 1;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < MAXN; i++) {

        }
    }
    void buildTree(vector<string> words) {
        
    }
    void insert(string word) {
        int cur = 1;
        passCnt[cur]++;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if(tree[cur][path]==0)
        }
    }
};