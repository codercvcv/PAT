#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[5] = {0}, count[5] = {0};
  int n, temp;
  cin >> n;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (temp % 5 == 0 && temp % 2 == 0) {
      a[0] += temp;
      count[0]++;
    }
    if (temp % 5 == 1) {
      if (flag == true) {
        a[1] += temp;
        flag = false;
      } else {
        a[1] -= temp;
        flag = true;
      }
      count[1]++;
    }
    if (temp % 5 == 2) {
      a[2]++;
      count[2]++;
    }
    if (temp % 5 == 3) {
      a[3] += temp;
      count[3]++;
    }
    if (temp % 5 == 4) {
      if (temp > a[4]) a[4] = temp;
      count[4]++;
    }
  }

  for (int i = 0; i < 5; ++i) {
    if (count[i] == 0) {
      printf("N");
    } else if (i == 3) {
      printf("%.1f", static_cast<double>(a[3]) / count[3]);
    } else {
      printf("%d", a[i]);
    }
    if (i < 4) cout << ' ';
  }
  return 0;
}