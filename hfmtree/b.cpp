#include <iostream>
#include <string>

#define ok 1
#define error -1

class HuffNode {
public:
  int weight, da;
  int prt;
  int lch;
  int rch;
};

class HuffMan {
private:
  void MakeTree();
  void SelectMin(int pos, int* s1, int* s2);
public:
  int len;
  int lnum;
  HuffNode* huffTree;
  std::string* huffCode;
  void MakeTree(int n, int wt[], char ct[]);
  void Coding();
  void dlt();
  int Decode(const std::string codestr, char txtstr[]);
};

void HuffMan::MakeTree(int n, int wt[], char ct[]) {
  int i;
  lnum = n;
  len = 2 * n - 1;
  huffTree = new HuffNode[2 * n];
  huffCode = new std::string[lnum + 1];
  for (i = 1; i <= n; i++) {
    huffTree[i].weight = wt[i - 1];
    huffTree[i].da = ct[i - 1];
  }
  for (i = 1; i <= len; i++) {
    if (i > n) {
      huffTree[i].weight = 0;
      huffTree[i].da = '0';
    }
    huffTree[i].prt = 0;
    huffTree[i].lch = 0;
    huffTree[i].rch = 0;
  }
  MakeTree();
}

void HuffMan::SelectMin(int pos, int* s1, int* s2) {
  int w1, w2, i;
  w1 = w2 = 10010;
  *s1 = *s2 = 0;
  for (i = 1; i <= pos; i++) {
    if (huffTree[i].prt == 0 && huffTree[i].weight < w1) {   
      w2 = w1;
      *s2 = *s1;
      w1 = huffTree[i].weight;
      *s1 = i;
    }
    else if(huffTree[i].weight<w2 && huffTree[i].prt==0) {
      w2 = huffTree[i].weight;
      *s2 = i;
    }
  }
}

void HuffMan::MakeTree() {
  int i, s1, s2;
  for (i = lnum + 1; i <= len; i++) {
    SelectMin(i - 1, &s1, &s2);
    huffTree[s1].prt = huffTree[s2].prt = i;
    huffTree[i].lch = s1;
    huffTree[i].rch = s2;
    huffTree[i].weight = huffTree[s1].weight+huffTree[s2].weight;
  }
}

void HuffMan::dlt() {
  len = 0;
  lnum = 0;
  delete[]huffTree;
  delete[]huffCode;
}

void HuffMan::Coding() {
  char* cd;
  int i, c, f, start;
  cd = new char[lnum];
  cd[lnum - 1] = '\0';
  for (i = 1; i <= lnum; ++i) {
    start = lnum - 1;
    for (c = i, f = huffTree[i].prt; f != 0; c = f, f = huffTree[f].prt) {
      if (huffTree[f].lch == c) {
        cd[--start] = '0';
      }
      else {
        cd[--start] = '1';
      }
    }
    huffCode[i] = new char[lnum - start];
    huffCode[i].assign(&cd[start]);
  }
  delete[]cd;
}

int HuffMan::Decode(const std::string codestr, char txtstr[]) {
  int i, k, c;
  char ch;
  c = len;
  k = 0;
  for (i = 0; i < codestr.length(); i++) {
    ch = codestr[i];
    if (ch == '0') c = huffTree[c].lch;
    else if (ch == '1') c = huffTree[c].rch;
    else return error;

    if (huffTree[c].lch == 0 && huffTree[c].rch == 0) {
      txtstr[k++] = huffTree[c].da;
      c = len;
    }
    else ch = '\0';
  }

  if (ch == '\0') return error;
  else txtstr[k] = '\0';
  return ok;
}

int main() {
  int n, i, m;
  int wt[800];
  char ct[800];
  HuffMan huftree;
  std::string codestr;
  char txtstr[800];
  std::cin >> n;
  for (i = 0; i < n; i++) {
    std::cin >> wt[i];
  }
  for (i = 0; i < n; i++) {
    std::cin >> ct[i];
  }
  huftree.MakeTree(n, wt, ct);
  huftree.Coding();
  std::cin >> m;
  while (m--) {
    std::cin >> codestr;
    if (huftree.Decode(codestr, txtstr) == 1) std::cout << txtstr << '\n';
    else std::cout << "error\n";
  }
  huftree.dlt();
  return 0;
}
