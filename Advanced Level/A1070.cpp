#include <bits/stdc++.h>
using namespace std;

struct Cake {
  double store_;
  double sum_;
  double price_;
};

int main() {
  int n, m;
  cin >> n >> m;
  double ans = 0;
  vector<Cake> cake(n);
  for (int i = 0; i < n; ++i) cin >> cake[i].store_;
  for (int i = 0; i < n; ++i) {
    cin >> cake[i].sum_;
    cake[i].price_ = cake[i].sum_ / cake[i].store_;
  }

  sort(cake.begin(), cake.end(),
       [](const Cake& c1, const Cake& c2) { return c1.price_ > c2.price_; });

  for (int i = 0; i < cake.size(); ++i) {
    if (m > cake[i].store_) {
      m -= cake[i].store_;
      ans += cake[i].sum_;
    } else {
      ans += cake[i].price_ * m;
      break;
    }
  }

  printf("%.2f", ans);

  return 0;
}