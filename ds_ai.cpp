#include <bits/stdc++.h>

struct data {
  std::string date;
  std::string type;
  int p1;
  int p2;
};

bool cmp_date(const data& a, const data& b) {
  return a.date < b.date;
}

void calc_avg(const std::vector<data>& data, int m) {
  if (data.size() < m) return;

  int s1=0, s2=0;
  for (int i = 0; i < m; i++) {
    s1 += data[i].p1;
    s2 += data[i].p2;
  }

  std::cout << data[m-1].date << ' ' << data[m-1].type << ' '
    << s1 / m << ' ' << s2 / m << '\n';

  for (size_t i = m; i < data.size(); i++) {
    s1 = s1 - data[i-m].p1 + data[i].p1;
    s2 = s2 - data[i-m].p2 + data[i].p2;

    std::cout << data[i].date << ' ' << data[i].type << ' '
      << s1 / m << ' ' << s2 / m << '\n';
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;
  std::vector<data> open;
  std::vector<data> close;

  for (int i = 0; i < n; i++) {
    data rec;
    std::cin >> rec.date >> rec.type >> rec.p1 >> rec.p2;
    if (rec.type == "open") {
      open.push_back(rec);
    } else {
      close.push_back(rec);
    }
  }

  std::sort(open.begin(), open.end(), cmp_date);
  std::sort(close.begin(), close.end(), cmp_date);

  calc_avg(open, m);
  calc_avg(close, m);

  return 0;
}