/**
 * trie - hash search
 * accepted code
 */
#include <iostream>
#include <string>
#include <queue>

int cnt = 0;

class trie {
public:
  trie *next[26] = {nullptr};

  void insert(std::string str) {
    trie *node = this;
    for (int i = 0; i < str.length(); i++) {
      char c = str[i];
      if (node->next[c-'a'] == nullptr) node->next[c-'a'] = new trie();
      node = node->next[c-'a'];
    }
  }

  int public_start(std::string st) {
    trie *node = this;
    cnt = 0;
    for (int i = 0; i < st.length(); i++) {
      char c = st[i];
      if (node->next[c-'a'] == nullptr) return 0;
      node = node->next[c-'a'];
    }
    dfs(node);
    return cnt;
  }

  void dfs(trie *node) {
    trie *tr = node;
    bool f = 1;
    for (int i = 0; i < 26; i++)
      if (tr->next[i]) {
        dfs(tr->next[i]);
        f = 0;
      }
    if (f) cnt++;
  }

  void lvord() {
    std::queue<trie*> qt;
    qt.push(this);
    while (!qt.empty()) {
      trie *node = qt.front();
      qt.pop();
      for (int i = 0; i < 26; i++) {
        if (node->next[i]) {
          std::cout << char(i+'a');
          qt.push(node->next[i]);
        }
      }
    }
  }
};

int main() {
  trie *tr = new trie();
  std::string s;
  int t;
  while (1) {
    std::cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      t = s[0] - '0';
      break;
    }
    tr->insert(s);
  }

  tr->lvord();
  std::cout << '\n';

  while (t--) {
    std::cin >> s;
    std::cout << tr->public_start(s) << '\n';
  }
  return 0;
}

