#include <bits/stdc++.h>
using namespace std;

struct Trie {
    array<Trie*, 26> nodes = {};
    bool exists = false;
    string word;
};

class Solution {
private:
    Trie *root = new Trie;
    unordered_set<string> result;
    
public:
    void insert(string& word) {
        Trie *curr = root;
        
        for (char c : word) {
            if (!curr->nodes[c - 'a']) {
                curr->nodes[c - 'a'] = new Trie;
            }
            
            curr = curr->nodes[c - 'a'];
        }
        
        curr->exists = true;
        curr->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, Trie* node) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }
        
        if (!board[x][y]) {
            return;
        }
        
        char c = board[x][y];
        
        Trie* next = node->nodes[c - 'a'];
        if (!next) {
            return;
        }
        
        if (next->exists) {
            result.insert(next->word);
        }
        
        board[x][y] = '\0';
        
        dfs(board, x - 1, y, next);
        dfs(board, x + 1, y, next);
        dfs(board, x, y - 1, next);
        dfs(board, x, y + 1, next);
        
        board[x][y] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words) {
            insert(word);
        }
        
        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[0].size(); ++y) {
                dfs(board, x, y, root);
            }
        }
        
        return {result.begin(), result.end()};
    }
};