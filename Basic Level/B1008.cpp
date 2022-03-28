#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  m %= n;
  vector<int> number(n);
  for (int i = 0; i < n; ++i) {
    cin >> number[i];
  }
  reverse(number.begin(), number.begin() + n - m);
  reverse(number.begin() + n - m, number.end());
  reverse(number.begin(), number.end());

  for (int i = 0; i < n; ++i) {
    cout << number[i];
    if (i != n - 1) cout << ' ';
  }
  return 0;
}