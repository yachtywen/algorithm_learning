#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 10001;
     int tree[MAXN][26];
     int passCnt[MAXN];
     string endWord[MAXN];
     int cnt;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTree(words);
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, 1, ans);
            }
        }
        clearTrie();
        return ans;
    }
    void buildTree(vector<string> words) {
        cnt = 1;
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
    }
    void insert(string word) {
        int cur = 1;
        passCnt[cur]++;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if (tree[cur][path] == 0) {
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
            passCnt[cur]++;
        }
        endWord[cur] = word;
    }
    int dfs(vector<vector<char>>& board, int i, int j, int c, vector<string>& ans) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 0) return 0;
        char tmp = board[i][j];
        int path = tmp - 'a';
        c = tree[c][path];
        if (c == 0 || passCnt[c] == 0) return 0;
        int fix = 0;
        if (!endWord[c].empty()) {
            fix++;
            ans.push_back(endWord[c]);
            endWord[c].clear();
        }
        board[i][j] = 0;
        fix += dfs(board, i - 1, j, c, ans);
        fix += dfs(board, i + 1, j, c, ans);
        fix += dfs(board, i, j - 1, c, ans);
        fix += dfs(board, i, j + 1, c, ans);
        board[i][j] = tmp;
        passCnt[c] -= fix;
        return fix;
    }
    void clearTrie() {
        for (int i = 1; i <= cnt; i++) {
            memset(tree[i], 0, sizeof(tree[i]));
            passCnt[i] = 0;
            endWord[i].clear();
        }
    }
};
