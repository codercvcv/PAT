#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> s1(n + 1, INT_MAX);
  for (int i = 0; i < n; ++i) cin >> s1[i];
  cin >> m;
  vector<int> s2(m + 1, INT_MAX);
  for (int i = 0; i < m; ++i) cin >> s2[i];
  int media_pos = (n + m - 1) / 2;
  int i = 0, j = 0, count = 0;
  int ans = 0;
  while (count < media_pos) {
    if (s1[i] < s2[j]) {
      i++;
    } else {
      j++;
    }
    count++;
  }

  s1[i] < s2[j] ? cout << s1[i] : cout << s2[j];

  return 0;
}