#include <iostream>
#define NULVAL -114514

class HashTable {
  int size;
  int *table;
  int hash(int val) {
    return val % 11;
  }

public:
  HashTable() {
    int n;
    std::cin >> size >> n;
    table = new int[size];
    for (int i = 0; i < size; i++) {
      table[i] = NULVAL;
    }

    int val, key;
    while (n--) {
      std::cin >> val;
      key = hash(val);
      for (int i = key; i < size + key; i++) {
        int id = i % size;
        if (table[id] == NULVAL) {
          table[id] = val;
          break;
        }
      }
    }
  }
  ~HashTable() {
    delete[] table;
  }

  void show() {
    for (int i = 0; i < size; i++) {
      if (table[i] != NULVAL)
        std::cout << table[i] << " \n"[i==size-1];
      else
        std::cout << "NULL" << " \n"[i==size-1];
    }

  }

  void search(int val) {
    int cmpcnt = 0, key = hash(val);
    bool f = 0;

    for (int i = key; i < size + key; i++) {
      int id = i % size;
      cmpcnt++;
      if (table[id] == val) {
        f = 1;
        std::cout << 1 << ' ' << cmpcnt << ' ' << id + 1 << '\n';
      } else if (table[id] == NULVAL) {
        break;
      }
    }

    if (!f)
      std::cout << 0 << ' ' << cmpcnt << '\n';
  }

};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    HashTable ht;
    ht.show();
    int k;
    std::cin >> k;
    while (k--) {
      int q;
      std::cin >> q;
      ht.search(q);
    }
  }
  return 0;
}