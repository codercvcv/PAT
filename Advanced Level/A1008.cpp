#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, now = 0, to, total = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> to;
    if (to > now)
      total += ((to - now) * 6);
    else
      total += ((now - to) * 4);
    total += 5;
    now = to;
  }

  cout << total;

  return 0;
}