/**
 * most basic sequence table structure
 * accepted
 */
#include <iostream>

#define errc 114514

class seqt {
  int *list;
  int mxsize, size;
public:
  seqt() {
    mxsize = 1000;
    size = 0;
    list = new int[mxsize];
  }

  int insert(int key, int val) {
    if (key > size || key < 0) return errc;
    for (int i = size; i > key; i--) {
      list[i] = list[i-1];
    }
    size++;
    list[key] = val;
    return 1;
  }

  int get(int key) {
    if (key >= size || key < 0) return errc;
    return list[key];
  }

  int del(int key) {
    if (key >= size || key < 0) return errc;
    for (int i = key; i < size; i++) {
      list[i] = list[i+1];
    }
    size--;
    return 1;
  }

  void show() {
    std::cout << size << ' ';
    for (int i = 0; i < size; i++)
      std::cout << list[i] << ' ';
    std::cout << '\n';
  }

};

int main() {
  int n;
  std::cin >> n;
  seqt st;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    st.insert(i, a);
  }

  st.show();

  for (int i = 0; i < 2; i++) {
    int a, b;
    std::cin >> a >> b;
    int res = st.insert(a-1, b);
    if (res!=errc) st.show();
    else std::cout << "error\n";
  }
  for (int i = 0; i < 2; i++) {
    int a;
    std::cin >> a;
    int res = st.del(a-1);
    if (res!=errc) st.show();
    else std::cout << "error\n";
  }
  for (int i = 0; i < 2; i++) {
    int a;
    std::cin >> a;
    int res = st.get(a-1);
    if (res!=errc) std::cout << res;
    else std::cout << "error\n";
  }
  return 0;
}