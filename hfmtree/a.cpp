#include <iostream>
#include <string>

typedef struct hnd {
  int w;
  int prt, lch, rch;
}hnd, *htr;

typedef char** hcd;

void encoding(htr &ht, hcd &hc, int *w, int n) {
  if (n<=1) return;
  int ln = 2*n-1;
  ht = (htr)malloc((ln+1) * sizeof(hnd));
  for (int i = 1; i <= n; i++) {
    ht[i].w = w[i-1];
    ht[i].prt = 0;
    ht[i].lch = 0;
    ht[i].rch = 0;
  }
  for (int i = n+1; i <= ln; i++) {
    ht[i].w = 0;
    ht[i].prt = 0;
    ht[i].lch = 0;
    ht[i].rch = 0;
  }

  for (int i = n+1; i <= ln; i++) {
    
  }
}