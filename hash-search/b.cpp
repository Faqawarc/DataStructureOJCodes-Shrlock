/*
  二次探测 hashtable
  accepted code
*/

#include <iostream>

#define NULVAL -114514

class HashTable {
  int size;
  int *table;

public:
  int hash(int val) {
    return val % 11;
  }

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
      int id = key % size;
      if (table[id] == NULVAL || table[id] == val) {
        table[id] = val;

      } else {

        int oper = 0;
        for (int i = 1;; i++) {
          oper = i * i;
          if (oper > size) oper %= size;

          if (table[(id+oper)%size] == NULVAL || table[(id+oper)%size] == val) {
            table[(id+oper)%size] = val;
            break;
          } else {

            if (id >= oper) {
              if (table[id-oper] == NULVAL || table[id-oper] == val) {
                table[id-oper] = val;
                break;
              }

            } else {
              if (table[size+id-oper] == NULVAL || table[size+id-oper] == val) {
                table[size+id-oper] = val;
                break;
              }
            }
          }
        }
      }
    }
  }

  ~HashTable() {
    delete[] table;
  }

  void show() {
    for (int i = 0; i < size; i++)
      if (table[i] == NULVAL)
        std::cout << "NULL" << " \n"[i==size-1];
      else
        std::cout << table[i] << " \n"[i==size-1];
  }

  void search(int val) {
    int cmpcnt = 0, key = hash(val), oper = 0;
    bool f = 0, syb = 1;
    int id = key;
    for (int i = 1;;) {
      cmpcnt++;
      if (table[id] == val) {
        f = 1;
        std::cout << 1 << ' ' << cmpcnt << ' ' << id+1 << '\n';
        break;
      } else if (table[id] == NULVAL) break;

      oper = i*i;
      if (oper>size) oper %= size;

      if (syb) {
        syb = 0;
        id = (key + oper) % size;
      } else {
        syb = 1;
        id = key - oper;
        if (id < 0) id += size;
        i++;
      }
    }

    if (!f) std::cout << 0 << ' ' << cmpcnt << '\n';
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