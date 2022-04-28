#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  int left = n - 1, num;
  vector<int> position(n);
  for (int i = 0; i < n; i++) {
    cin >> num;
    position[num] = i;
    if (num == i && num != 0) left--;
  }

  int k = 1;
  while (left > 0) {
    if (position[0] == 0) {
      while (k < n) {
        if (position[k] != k) {
          swap(position[0], position[k]);
          ans++;
          break;
        }
        k++;
      }
    }

    while (position[0] != 0) {
      swap(position[0], position[position[0]]);
      ans++;
      left--;
    }
  }

  cout << ans;
  return 0;
}